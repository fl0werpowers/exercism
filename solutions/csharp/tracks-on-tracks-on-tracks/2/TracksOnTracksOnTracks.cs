public static class Languages
{
    public static List<string> NewList() => new List<string>();

    public static List<string> GetExistingLanguages() => new List<string>() { "C#", "Clojure", "Elm" };

    public static List<string> AddLanguage(List<string> languages, string language) => new List<string>(languages) { language };

    public static int CountLanguages(List<string> languages) => languages.Count;

    public static bool HasLanguage(List<string> languages, string language) => languages.Contains(language);

    public static List<string> ReverseList(List<string> languages) => languages.Reverse<string>().ToList();

    public static bool IsExciting(List<string> languages) =>
        languages.Count != 0
        && (languages.First() == "C#"
            || (languages.ElementAt(1) == "C#" && (languages.Count == 2
            || languages.Count == 3
        )));

    public static List<string> RemoveLanguage(List<string> languages, string language) => languages.Where(lang => lang != language).ToList();

    public static bool IsUnique(List<string> languages)
    {
        var set = new HashSet<string>(languages);

        if (set.Count != languages.Count) return false;
        return true;
    }
}
