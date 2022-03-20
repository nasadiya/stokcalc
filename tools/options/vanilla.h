#include <cmath>
#include <random>
#include <boost/math/distributions/normal.hpp>

double max(double a, double b) {
    double result = a;
    if (a < b) result = b;
    return result;
}

enum option_type {
    put,
    call
};

class vanilla_option {
    private:
        double strike;
        option_type opt_type;
    public:
        vanilla_option(double str, option_type opt) : strike(str), opt_type(opt) {}
        double payoff(double underlying){

            switch (opt_type)
            {
            case call:
                return max(0.0, underlying - strike);
            
            case put:
                return max(0.0, strike - underlying);

            default:
                throw("unknown option type");
            }
        }
};

double vanilla (double volatility, double time_to_expiry, double strike, \
                double risk_free, double asset_price, option_type opt = call)
{   
    boost::math::normal norm_dist;

    double d_plus = (1/(volatility * sqrt(time_to_expiry))) * \
                    (log(asset_price/strike) + \
                    (risk_free + 0.5 * volatility * volatility) * time_to_expiry);
    double d_minus = d_plus - volatility * sqrt(time_to_expiry);
    double discount = exp( -1 * risk_free * time_to_expiry);

    switch (opt)
    {
    case call:
        return asset_price * boost::math::cdf(norm_dist,d_plus) - \
                    discount * strike * boost::math::cdf(norm_dist, d_minus);

    case put:
        return discount * strike * boost::math::cdf(norm_dist, -1 * d_minus) - \
                    asset_price * boost::math::cdf(norm_dist,-1 * d_plus);

    default:
        throw("unknown option type");
    }
   
}   

double vanilla_simulate (double volatility, double time_to_expiry, double strike, \
                         double risk_free, double asset_price, long sample_size = 10000, \
                         option_type opt= call)
{   
    random_device r;
    mt19937 gen(r());
    normal_distribution<> N{0,1};
    
    vanilla_option option_class(strike, opt);
    
    // Non stochastic terms
    double risk_free_term = risk_free * time_to_expiry;
    double risk_free_exponent = exp(- 1 * risk_free_term);
    double static_term = risk_free_term - 0.5 * volatility * volatility *  time_to_expiry;
    double volatility_term = volatility * sqrt(time_to_expiry);

    // for each sample compute weighted sum.
    double variable_term = 0;

    for (int i = 0; i < sample_size; i++)
        variable_term += option_class.payoff(asset_price * exp(static_term + volatility_term * N(gen)));
    
    return risk_free_exponent * variable_term / sample_size;

}
