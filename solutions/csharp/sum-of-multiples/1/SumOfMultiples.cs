public static class SumOfMultiples
{
    public static int Sum(IEnumerable<int> multiples, int max) =>
        multiples.Select(number =>
        {
            if (number == 0) return [0];
            var output = new List<int>();
            for (int i = number; i < max; i++)
            {
                if (i % number == 0)
                    output.Add(i);
            }
            return output;
        }).Aggregate(new HashSet<int>(), (accumulator, nextList) =>
        {
            accumulator.UnionWith(nextList);
            return accumulator;
        }
        ).Sum();
}
