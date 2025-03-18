# **Configuring Network Interfaces in Linux**

This guide explains how to manually configure a network interface in Linux using the `ip` command.

---

## **1. Check Available Network Interfaces**
List all network interfaces:

```bash
ip link show
ip addr show wlo1
```
![show interface](images/1.%20link%20show.png)
![show wlo1](images/2.%20show%20wlo1.png)

---

## **2. Assign an IP Address**
Assign an IP address to the desired interface (e.g., wlo1):

```bash
sudo ip addr add 192.168.31.180/24 dev wlo1
```

---

## **3. Bring the Interface Up**
Enable the interface to make it active:

```bash
sudo ip link set dev wlo1 up
```

---

## **4. Add a Default Gateway**
Set the default gateway for the network:

```bash
sudo ip route add default via 192.168.31.1
```
![assign & set UP & Gateway](images/3.%20assign%20and%20set%20up.png)

---

## **5. Verify Configuration**
Check Assigned IP Address

```bash
ip addr show wlo1
```
![show assigned wlo1](images/4.%20show%20wlo1.png)

Verify Routing Table

```bash
ip route show
```
![route](images/5.%20ip%20route.png)

---