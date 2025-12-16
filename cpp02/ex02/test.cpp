#include <iostream>
#include <string>
#include <list>

struct Youtube
{
        std::string Name;
        int     SubscribersCount;
        Youtube(std::string name, int subscribersCount){
                Name = name;
                SubscribersCount = subscribersCount;
        }

        bool    operator==(const Youtube& channel) const
        {
                return( this->Name == channel.Name);
        }
};
struct MyCollection
{
        std::list<Youtube>myChannels;

        void operator +=(Youtube& channel)
        {
                myChannels.push_back(channel);
        }
        void operator -=(Youtube& channel)
        {
                myChannels.remove(channel);
        }
};

std::ostream& operator<<(std::ostream& COUT, Youtube& ytChannel)
{
    COUT << "Name: " << ytChannel.Name << std::endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << std::endl;
    return COUT;
}

std::ostream& operator<<(std::ostream& COUT, MyCollection& myCollection)
{
        for (std::list<Youtube>::iterator it = myCollection.myChannels.begin(); it != myCollection.myChannels.end(); ++it)
        {
                COUT << *it;
                COUT << "------------------------" << std::endl;
        }
        return COUT;
}

int     main()
{
        Youtube yt1 = Youtube("Beauty Channel", 7500);
        Youtube yt2 = Youtube("Lubna Channel", 1000);
        MyCollection myCollection;
        myCollection += yt1;
        myCollection += yt2;
        // myCollection -= yt2;

        std::cout<< myCollection;
}