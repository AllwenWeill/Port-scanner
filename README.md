# Port-scanner
This simple port scanner is base on c++ implementation. The running environment is Linux.
The core idea of this scanner is to send requests to all port numbers from 0 to 65535. If someone respond this request, that means the port is open.(just like returning an ack)
The "serverScan" is file of scaning port, if the server port is detected, it can automatically connect to the server with port number 5000, it can enter in a command of "createfile", this command can create a file named "fileTest.txt" on the server.
The "serverTest" is the server program used to test the port scanner.

Implementation effect:

![image](https://github.com/AllwenWeill/IMG/blob/main/%E6%88%AA%E5%9B%BE1.png)
![image](https://github.com/AllwenWeill/IMG/blob/main/%E6%88%AA%E5%9B%BE2.png)
![image](https://github.com/AllwenWeill/IMG/blob/main/%E6%88%AA%E5%9B%BE3.png)
![image](https://github.com/AllwenWeill/IMG/blob/main/%E6%88%AA%E5%9B%BE4.png)
