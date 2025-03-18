# **MAC Address Table Inspection and Configuration in Linux**

## **1. Inspecting the MAC Address Table**

### **Using the `bridge` Command**
#### **List All Network Bridges**
To check active network bridges:
```bash
bridge link
```
![bridge link](images/1.%20bridge%20link.png)

This command displays all interfaces and their bridge associations.

#### **View the MAC Address Table**
To see the Forwarding Database (FDB) for a bridge:
```bash
bridge fdb show
```
![fdb](images/2.%20bridge%20fdb.png)

This command lists the MAC addresses learned by the switch along with associated interfaces.

---

### **Using the `ip` Command**
#### **List All Interfaces**
```bash
ip link show
```
![ip link](images/3.%20ip%20link.png)

#### **View Detailed Interface Information**
```bash
ip -d link show
```
---

## **2. Demonstrating basic switch operation**
### Step 1: Identify Suitable Interfaces
List available interfaces:

```bash
ip link show
```
### Step 2: Create a New Bridge
Create a custom bridge (br0) and activate it:

```bash
sudo ip link add name br0 type bridge
sudo ip link set dev br0 up
```
### Step 3: Add Interfaces to the Bridge
Add an interface (e.g., tap-1e376645a40) to the bridge:

```bash
sudo ip link set dev tap-1e376645a40 master br0
```
Ensure the interface is active:

```bash
sudo ip link set dev tap-1e376645a40 up
```
![setting bridge](images/4.%20bridge%20demo.png)

### Step 4: Generate Traffic
Assign IP addresses to devices connected to the bridge and use ping to generate traffic: (Router IP)

```bash
ping 192.168.31.1 
```
![ping](images/5.%20ping%20router.png)

### Step 5: Inspect the MAC Address Table
After generating traffic, inspect the MAC table:

```bash
bridge fdb show dev br0
```
![fdb show](images/6.%20show.png)

---

## **3. Types of MAC Addresses in the Table**
### Multicast Addresses (Starting with 33:33 or 01:00)
Examples: 33:33:00:00:00:01, 01:00:5e:00:00:01

Used for protocols like IPv6 Neighbor Discovery, IGMP, or multicast traffic handling.

### Unicast Addresses
Example: f2:26:af:80:fd:59

Likely belongs to a device connected to the bridge. The master flag indicates it was learned from an external interface.

---

## **4. What This Signifies About the Bridge's Operation**
The br0 bridge is actively functioning as a Layer 2 switch, as evidenced by:

Learned MAC addresses from connected devices (f2:26:af:80:fd:59).
Registered multicast and permanent addresses for managing multicast traffic.
Traffic forwarding based on MAC addresses, confirming that the bridge is learning and operating correctly.

---
