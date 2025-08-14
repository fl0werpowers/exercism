static class AssemblyLine
{
    const int CARS_PER_SPEED = 221;

    public static double SuccessRate(int speed)
    {
        switch (speed)
        {
            case 0: return 0d;
            case 1: case 2: case 3: case 4: return 1.0;
            case 5: case 6: case 7: case 8: return 0.9;
            case 9: return 0.8;
            case 10: return 0.77;
            default: return 0d;
        }
    }

    public static double ProductionRatePerHour(int speed) => CARS_PER_SPEED * speed * SuccessRate(speed);

    public static int WorkingItemsPerMinute(int speed) => (int)(ProductionRatePerHour(speed) / 60);
}
