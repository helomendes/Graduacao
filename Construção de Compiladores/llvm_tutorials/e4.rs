fn safe_div(n: u64, d: u64) -> u64 {
    if d == 0 { return u64::MAX; }
    n / d
}
