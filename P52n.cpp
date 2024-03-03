#include<iostream>
using namespace std;
namespace checkNumber{
int isArmstrong(int num){
    int original=num;
    int sum=0;
    while(num!=0){
        int digit = num%10;
        sum+=digit*digit*digit*digit*digit;
        num/=10;
    } 
 return original==sum; 
 }
int isPalidrone(int num){
    int original = num;
    int reverse=0;
    while(num!=0){
        reverse=reverse*10+num%10;
        num/=10;
    }
    return original==reverse;
 }
}
int main(){
    using namespace checkNumber;
    int num;
    cout<<"Enter Number upto 5 digit :"<<endl;
    cin>>num;
    if(num<0||num>99999){
        cout<<"Entered Number is Invalid."<<endl;
        return 1;
    }
    if(isArmstrong(num)){
        cout<<num<<" is a Armstrong Number"<<endl;
    }
    else{
        cout<<num<<" is not a Armstrong Number"<<endl;
    }
    if(isPalidrone(num)){
        cout<<num<<" is a Palidrone Number"<<endl;
    }
    else{
        cout<<num<<" is not a Palidrone Number"<<endl;
    }
    return 0;
}