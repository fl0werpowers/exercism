static class AssemblyLine
{
    const int CARS_PER_SPEED = 221;

    public static double SuccessRate(int speed) => speed switch
    {
        < 1 => 0.0,
        <= 4 => 1.0,
        <= 8 => 0.9,
        9 => 0.8,
        10 => 0.77,
        _ => 0d,
    };

    public static double ProductionRatePerHour(int speed) => CARS_PER_SPEED * speed * SuccessRate(speed);

    public static int WorkingItemsPerMinute(int speed) => (int)(ProductionRatePerHour(speed) / 60);
}
