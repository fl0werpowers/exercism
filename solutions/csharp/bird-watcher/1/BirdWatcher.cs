class BirdCount
{
    private int[] birdsPerDay;

    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek()
    {
        return new[] { 0, 2, 5, 3, 7, 8, 4 };
    }

    public int Today()
    {
        return this.birdsPerDay.Last();
    }

    public void IncrementTodaysCount()
    {
        this.birdsPerDay[this.birdsPerDay.Length - 1]++;
    }

    public bool HasDayWithoutBirds()
    {
        foreach (var day in this.birdsPerDay)
        {
            if (day == 0) return true;
        }
        return false;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        int birdsVisited = 0;
        for (int day = 0; day < numberOfDays; day++)
        {
            birdsVisited += this.birdsPerDay[day];
        }
        return birdsVisited;
    }

    public int BusyDays()
    {
        int busyDays = 0;
        for (int day = 0; day < this.birdsPerDay.Length; day++)
        {
            if (this.birdsPerDay[day] >= 5) busyDays++;
        }
        return busyDays;
    }
}
