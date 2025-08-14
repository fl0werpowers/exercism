using System.Collections;

public static class FlattenArray
{
    public static IEnumerable Flatten(IEnumerable input)
    {
        var output = new List<object>();

        foreach (var element in input)
        {
            if (element == null) continue;

            if (element is IEnumerable enumerable)
            {
                foreach (var nestedItem in Flatten(enumerable))
                {
                    output.Add(nestedItem);
                }
            }
            else output.Add(element);
        }

        return output;
    }
}
