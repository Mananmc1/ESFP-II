#include<iostream>
using namespace std;
namespace bfcalculator{
    int calculatebf(int distance){
    int fare;
    if(distance>=0 && distance<=20){
        fare=1;
    }
    else if(distance>=21&& distance<=40){
        fare=2;
    }
    else if (distance>=41 && distance<=60){
        fare=3;
    }
    else if (distance>=61 && distance<=80){
        fare=4;
    }
    else if (distance>=81 && distance<=100){
        fare=5;
    }
    else{
        fare=6;
    }
    return fare*distance;
    }
}
int main(){
    int distance;
    using namespace bfcalculator;
    cout<<"Enter the distance in KMs:";
    cin>>distance;
    int totalfare=calculatebf(distance);
    cout<<"Total fare of journey is :"<<totalfare;
    return 0;
}