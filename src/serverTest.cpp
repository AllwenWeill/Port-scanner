#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <iostream>
#include <pthread.h>
#include <vector>
#define Max_Port 65535
#define Min_Port 0
using namespace std;
vector<int> portList;
bool scanServer();
int main(){
    for(int currPort=Min_Port;currPort<=Max_Port;currPort++)
    {
        struct sockaddr_in server_addr;
        int server_socket;
        bzero(&server_addr, sizeof(server_addr)); // 置字节字符串前n个字节为0，包含'\0'
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htons(INADDR_ANY); // 转小端,INADDR_ANY就是指定地址为0.0.0.0的地址
        server_addr.sin_port = htons(currPort); 
        // 创建一个Socket
        server_socket = socket(PF_INET, SOCK_STREAM, 0);
        if(server_socket<0){
            perror("socket error");
            sleep(1);
        }
        if(connect(server_socket,(struct sockaddr*)&server_addr,sizeof(struct sockaddr))==0){
            cout<<"可见端口："<<currPort<<endl;
            portList.push_back(currPort);
            sleep(1);
        }
        close(server_socket);//注意关闭！！
    }
    if(scanServer()){
        cout<<"-------------------------"<<endl;
        cout<<"Success:扫描到服务器端口！"<<endl;
        cout<<"-------------------------"<<endl;
        sleep(2);
        struct sockaddr_in server_addr;
        int server_socket;
        bzero(&server_addr, sizeof(server_addr)); // 置字节字符串前n个字节为0，包含'\0'
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(5000);
        server_socket = socket(PF_INET, SOCK_STREAM, 0);
        if(connect(server_socket,(struct sockaddr*)&server_addr,sizeof(struct sockaddr))==0)
            cout<<"Success:与<服务器端>连接成功!"<<endl;
        else
            cout<<"Error:与<服务器端>连接失败!"<<endl;
        char cmpTemple[100]="createfile";
        while(1){
            char send_buf[100]{0}, recv_buf[100]{0};
            cout<<"请输入命令："<<endl;
            cin>>send_buf;
            if(strcmp(send_buf,cmpTemple)!=0){
                cout<<"Error:错误命令！"<<endl;
                continue;
            }
            if(send(server_socket,send_buf,100,0)<0){
                cout<<"Error:发送失败！"<<endl;
                break;
            }
            else
                cout<<"Success:发送<"<<send_buf<<">命令成功！"<<endl;
            if(recv(server_socket,recv_buf,100,0)<0){
                cout<<"Error:接受失败！"<<endl;
                break;
            }
        }
    }
    else
        cout<<"Error:未扫描到服务器端口！"<<endl;
    return 0;   
}
bool scanServer(){
    for(int i=0;i<portList.size();i++){
        if(portList[i]==5000){
            return true;
        }
    }
    return false;
}