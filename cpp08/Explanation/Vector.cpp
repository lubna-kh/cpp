#include <iostream>
#include <vector>
#include <algorithm>



int main()
{
    std::vector<int> v1(3,0);
    std::vector<int> v2;

    v2  =  {1,2,3,4,5,6,7,8,9};

    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";

    v1.clear();//this will earse all the elements inside the vector
    v1.assign(v2.begin(), v2.end());//this will copy all the elements from v2 to v1
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";
    
    std::cout<<v1.back()<<std::endl;
    std::cout<<v1.front()<<std::endl;
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"pop_back and push_back:"<<std::endl;
    v1.pop_back();
    v1.push_back(1);
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n---------------------------------------------------\n";
    
    std::cout<<"emplace tests:\n"<<std::endl;
    v1.emplace(v1.begin(), 1000);
    v1.emplace_back(11);
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }

    std::cout<<"\n---------------------------------------------------\n";

    std::cout<<"erase tests....\n"<<std::endl;

    v2.erase(v2.begin()+2);//this will erase the 3rd element from the vector
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";

    v2.erase(v2.begin()+1, v2.begin()+4);//this will erase elements from index 1 to 3 (4 is not included)
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n";

    v1.erase(find(v1.begin(), v1.end(), 1000));//this will erase the element 1000 from the vector
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"swap test:\n"<<std::endl;
    
    v2.swap(v1);//this will swap the contents of v1 and v2
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"resize and reserve tests:\n"<<std::endl;

    v1.resize(15);//this will resize the vector to 15 elements if size is less than 15 it will add 0's at the end if size is greater than 15
    v1.reserve(20);//this will allocate memory for 20 elements but size will remain same
    
    std::cout<<"capacity= "<<v1.capacity()<<std::endl;//capacity is the total memory allocated for the vector
    std::cout<<"size= "<<v1.size()<<std::endl;//size is the number of elements in the vector
    
    v1.insert(v1.begin()+3, 100);
    
    std::cout<<"capacity= "<<v1.capacity()<<std::endl;
    std::cout<<"size= "<<v1.size()<<std::endl;
    
    for(auto x : v1)
    {
        std::cout<<x<<" ";
    }
    std::cout<<"\n---------------------------------------------------\n";
    std::cout<<"2D array tests:\n"<<std::endl;
    
    std::vector<std::vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (size_t i=0;i < matrix1.size();i++)
    {
        for(size_t j = 0;j < matrix1[i].size();j++)
            std::cout<<matrix1[i][j]<<" ";
    }
    std::cout<<"\n-----------------------\n";

    //3x4 matrix with all elements initialized to 1
    std::vector<std::vector<int>>matrix(3, std::vector<int>(4,1));

    for (size_t i=0;i < matrix.size();i++)
    {
        for(size_t j = 0;j < matrix[i].size();j++)
            std::cout<<matrix[i][j]<<" ";
    }
    std::cout<<"\n---------------------------------------------------\n";
    return 0;
}