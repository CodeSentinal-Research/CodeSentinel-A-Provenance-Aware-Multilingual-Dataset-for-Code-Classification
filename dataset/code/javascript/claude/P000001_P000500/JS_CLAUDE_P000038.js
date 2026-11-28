function compoundInterest(principal, rate, time) {
    const amount = principal * Math.pow(1.0 + rate / 100.0, time);
    return amount - principal;
}

module.exports = { compoundInterest };
