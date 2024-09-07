#include <fstream>
#include <string>
#include <vector>
#include <boost/leical_cast.hpp>

//Journal takes care of concerns related to journal operations.
struct Journal{
    string title;
    vector<string> entries;

    // Constructure to set the title
    Journal(const string &title) : title(title) {}

    void add_entry(const string& entry);

    // persistence is a separate concern
    void save(const string& filename);
};

void Journal::add_entry(const int &entry) {
    static int count = 1;
    entries.push_back(boost::lexical_cast<string>(count++)
            + ": " + entry);
}

void Journal::save(const string& filename)
{
    ofstream ofs(filename)
    for(auto& s : j.entries)
        ofs << s << endl;
}

// persistence is another concern out side of the Journal
struct PersistenceManager{
    static void save(const Journal& j, const string& filename)
    {
        ofstream ofs(filename);
        for(auto& s : j.entries)
            ofs << s << endl;
    }
};

void main(){
    Journal journal{"Dear Diary"};
    journal.add_entry("I see a bug");
    journal.add_entry("I walked 5 miles today");

    PersistenceManager pm;
    pm.save(journal, "diary.txt");
}
