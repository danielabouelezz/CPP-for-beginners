#include <bits/stdc++.h> 

#define all(v) ((v).begin()), ((v).end())


// If your function is not a CORRECT less than operator < , RTE probably will happen on a big test case. 
// If a < b, then b < a = false
// a and b are considered equivalent if (!(a < b) && !(b < a))

bool sortPairsCmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first * b.second < a.second * b.second;
}

void SetAndPairAndMapBasicTest()
{
    // Pair
    std::pair<int, char> p1 = std::make_pair(10, 'z');
    std::pair<std::string, std::pair<int, char>> p2 = std::make_pair("mostafa", p1);

    std::cout<<p2.first<<"\n";
    std::cout<<p2.second.first<<"\n";
    std::cout<<p2.second.second<<"\n";

    // Rule: any algorithm / data structure that need to compare data, e.g. sort
    // will use basic data types to compare (e.g. 3 < 5), or you provide a comparator / compare function

   std::vector<std::pair<int, int> > vp; 
   vp.push_back(std::make_pair(1, 2));
   vp.push_back(std::make_pair(4, 4)); 
   sort(all(vp), sortPairsCmp); 

   /////////////////////////////////////////////

   std::set<std::string> strSet; 
   strSet.insert("mostafa");
   strSet.insert("ali");

   if(strSet.count("mostafa"));
        std::cout<<"Mostafa is in Set\n";

    std::set<std::string>::iterator strIt = strSet.lower_bound("mostafa");
    strIt = strSet.find("mostafa");

    // replace(all(strSet), "mostafa", "hani"); // In maps and sets, don't try intermediate playing. The are based on keys. 

    std::map<std::string, int> mp; 
    mp["Mostafa"] = 10; 
    mp["Saad"] = 20;

    // You could iterate on map and set normally like vector. Never to change keys while iterating
    // Another way, convert map to vector of pair: key, value

    std::vector<std::pair<std::string, int> > mptov(all(mp));

    for(int i{0}; i < (int)mptov.size(); ++i)
        std::cout<< mptov[i].first << " " << mptov[i].second <<"\n";

    // Map and set are log(n)
    // Multiset & multimap same but allows keys repetition
}

int main()
{
    SetAndPairAndMapBasicTest();
}