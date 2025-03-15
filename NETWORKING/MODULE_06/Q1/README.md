# **Task: Capture and Analyze ARP Packets**

## **Objective**
The goal of this task is to capture and analyze ARP packets. This includes:
1. Inspecting ARP request and reply frames.
2. Understanding the role of the sender's IP and MAC address in these packets.

---

## **1. ARP Analysis (Router MAC Resolution)**

### **Setup**
- **Environment**: A PC connected to a router, which is connected with a Server.
- **Source Device**: Laptop (`192.168.0.1`).
- **Target Device**: Router (`192.168.0.254` acting as the default gateway).
- **Tool**: Cisco PPacket Tracer

![Setupp](images/1.%20Setup.png)

---

### **Router Configuration**

Router> enable

Router# configure terminal

Router(config)# interface FastEthernet0/0

Router(config-if)# ip address 192.168.0.254 255.255.255.0

Router(config-if)# no shutdown

Router(config-if)# exit

Router(config)# interface FastEthernet0/1

Router(config-if)# ip address 10.10.10.1 255.255.255.0

Router(config-if)# no shutdown

Router(config-if)# exit

Router(config)# exit

Router# write memory

---

### **Observation 1: ARP Request**

- **Details**:
  - **Sender MAC**: `00:0A:E6:3E:FD:E1` (PC).
  - **Sender IP**: `192.168.0.1`.
  - **Target MAC**: `FF:FF:FF:FF:FF:FF` (Broadcast).
  - **Target IP**: `192.168.0.254`.

- **Analysis**:
  The ARP Request is broadcast to all devices on the network (`FF:FF:FF:FF:FF:FF`) to find the MAC address for the router (`192.168.0.254`).

![ARP request](images/2.%20ARP%20request.png)

---

### **Observation 2: ARP Reply**

- **Details**:
  - **Sender MAC**: `00:1D:92:3B:4C:2A` (Router).
  - **Sender IP**: `192.168.0.254`.
  - **Target MAC**: `00:0A:E6:3E:FD:E1` (PC).
  - **Target IP**: `192.168.0.1`.

- **Analysis**:
  The ARP Reply is sent as a unicast to the requesting device (`00:0A:E6:3E:FD:E1`), providing the router's MAC address (`00:1D:92:3B:4C:2A`).

![ARP reply](images/3.%20ARP%20reply.png)

---

### **ARP Table in PC and Router**

**Screenshots**:
- ARP Table - PC: ![PC ARP](images/6.%20ARP%20cache%20in%20PC%20A.png)
- ARP Table - Router: ![Router ARP](images/5.%20ARP%20cache%20in%20Router.png)

---

## **2. ICMP Behavior Analysis**

### **Traffic Summary**
When the PC pings a device outside the local network:
- **Source Device**: PC (`192.168.0.1`).
- **Intermediate Device**: Router (`192.168.0.254`).
- **Destination Device**: Server (`10.10.10.10`).

### **Packet Details**
- The ICMP request uses:
  - **Destination IP**: `10.10.10.10` (Server).
  - **Destination MAC**: `00:1D:92:3B:4C:2A` (Router).
- The ICMP packet is encapsulated at Layer 2 using the router's MAC address as the next-hop destination.

![ICMP](images/4.%20ICMP%20with%20Router%20MAC%20and%20Server%20IP.png)

**Ping Output**:
```plaintext
Pinging 10.10.10.10 with 32 bytes of data:
Reply from 10.10.10.10: bytes=32 time<1ms TTL=128
Reply from 10.10.10.10: bytes=32 time<1ms TTL=128
