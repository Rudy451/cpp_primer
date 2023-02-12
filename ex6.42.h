#include <string>

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending="s")
{
        return (ctr > 1) ? word + ending : word;
}
