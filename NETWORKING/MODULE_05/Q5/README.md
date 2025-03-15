# **Task: Subnet a Network and Verify Connectivity**

## **Objective**
1. Divide the given IP address range `192.168.1.0/24` into **4 subnets**.
2. Manually calculate the new subnet mask and the range of valid IP addresses for each subnet.
3. Assign IP addresses from these subnets to devices in Packet Tracer.
4. Verify connectivity between devices using ping tests.

---

## **1. Subnetting Details**

### **Given IP Address Range**
- Network: `192.168.1.0/24`
- Subnet Mask: `255.255.255.0` (default for /24)

### **Subnet Calculation**
To divide the network into **4 subnets**:
- **Step 1**: Increase the subnet mask by **2 bits** (to divide by 4).
  - New Subnet Mask: `/26` or `255.255.255.192`
  - Each subnet will have `2^(32-26) = 64` IP addresses (including network and broadcast addresses).
- **Step 2**: Determine the subnet ranges.

| **Subnet** | **Network Address** | **Broadcast Address** | **Valid Host Range**        |
|------------|----------------------|------------------------|-----------------------------|
| Subnet 1   | `192.168.1.0`       | `192.168.1.63`        | `192.168.1.1 - 192.168.1.62` |
| Subnet 2   | `192.168.1.64`      | `192.168.1.127`       | `192.168.1.65 - 192.168.1.126` |
| Subnet 3   | `192.168.1.128`     | `192.168.1.191`       | `192.168.1.129 - 192.168.1.190` |
| Subnet 4   | `192.168.1.192`     | `192.168.1.255`       | `192.168.1.193 - 192.168.1.254` |

---

## **2. Packet Tracer Setup**

### **Network Diagram**
The network is divided into 4 subnets, with devices assigned IPs accordingly:
- **Subnet 1**: PC1 and PC2.
- **Subnet 2**: PC3 and PC4.
- **Subnet 3**: PC5 and PC6.
- **Subnet 4**: PC7 and PC8.

![Network Diagram](images/1.%20Setup.png)
![Static Route Setup](images/2.%20Static%20Router%20Configuration.png)

### **Device IP Assignments**
| **Device** | **Subnet** | **Assigned IP**        | **Subnet Mask**    |
|------------|------------|------------------------|--------------------|
| PC1        | Subnet 1   | `192.168.1.1`         | `255.255.255.192`  |
| PC2        | Subnet 1   | `192.168.1.2`         | `255.255.255.192`  |
| PC3        | Subnet 2   | `192.168.1.65`        | `255.255.255.192`  |
| PC4        | Subnet 2   | `192.168.1.66`        | `255.255.255.192`  |
| PC5        | Subnet 3   | `192.168.1.129`       | `255.255.255.192`  |
| PC6        | Subnet 3   | `192.168.1.130`       | `255.255.255.192`  |
| PC7        | Subnet 4   | `192.168.1.193`       | `255.255.255.192`  |
| PC8        | Subnet 4   | `192.168.1.194`       | `255.255.255.192`  |

---

## **3. Ping Test Results**

### **Connectivity Verification**
Use `ping` commands to verify communication between devices within and across subnets.

![Ping](images/3.%20Ping.png)


