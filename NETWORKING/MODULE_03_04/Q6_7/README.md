# **Network Troubleshooting: Analyzing Connectivity Between Different Networks**

## **1. Network Setup**
In this scenario, two PCs are connected to a switch. The IP addresses are deliberately configured in **different networks** to demonstrate the inability to communicate directly.

- **PC0**: `192.168.1.1`
- **PC1**: `200.10.10.10`
- Both are connected to the same switch.

![Setup](images/1.%20Setup.png)

---

## **2. Steps Taken**

### **Ping Test**
```bash
ping 200.10.10.10
```
![Ping](images/2.%20ping.png)

Observation:
The ping from PC0 to PC1 failed with the response:
```plaintext
Request timed out.
```
This happened because the two devices are on different IP networks and there is no routing device to bridge the communication.

### **Verify IP Configuration**
Used the ipconfig command on both PCs to ensure that IP addresses were properly configured.
```bash
ipconfig
```
Verification Result:

PC0: IP address confirmed as 192.168.1.1.

PC1: IP address confirmed as 200.10.10.10.

![ipconfig PC0](images/3.%20ipconfig%20PC0.png)
![ipconfig PC1](images/4.%20ipconfig%20PC1.png)

### **Traceroute to Identify Packet Drop**
Used the traceroute (or tracert on Windows) command to analyze where the packet drops occur when attempting to communicate with PC1.
```bash
traceroute 200.10.10.10
```
![Traceroute](images/5.%20traceroute.png)

Observation:
The traceroute indicated that the packets never left the source PC (PC0) because there is no route to reach PC1's network.

## **3. Analysis and Conclusion**
Reason for Failure:
The two PCs are configured in different networks (192.168.1.0/24 and 200.10.10.0/24), and there is no router or Layer 3 device to enable communication between them.
