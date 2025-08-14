using System.Collections;

public static class FlattenArray
{
    public static IEnumerable Flatten(IEnumerable input)
    {
        var output = new List<object>();

        foreach (var element in input)
        {
            if (element == null) continue;

            if (element.GetType().IsArray)
            {
                var nestedArray = Flatten(element as IEnumerable);

                foreach (var nestedItem in nestedArray)
                {
                    output.Add(nestedItem);
                }
            }
            else output.Add(element);
        }

        return output;
    }
}
