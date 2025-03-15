# **Task: Manually Configure Static IPs and Verify Connectivity**

## **Objective**
1. Manually configure static IP addresses on client devices (e.g., PCs).
2. Verify connectivity using the `ping` command.

---

## **1. Steps to Configure Static IPs**

### **Step 1: Identify Active Interface**
An active network interface is chosen. The output below illustrates identifying the active interface `wlo1` on your device:

```bash
dk@dk-Vivobook-ASUS:~$ ip addr show dev wlo1
2: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether a0:59:50:39:af:fd brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
    inet 192.168.31.188/24 brd 192.168.31.255 scope global dynamic noprefixroute wlo1
       valid_lft 26004sec preferred_lft 26004sec
    inet6 2409:40f4:111f:c2f2:e28a:eef9:cba0:728c/64 scope global temporary dynamic 
       valid_lft 18205sec preferred_lft 18205sec
    inet6 2409:40f4:111f:c2f2:1d04:21d:1325:fa9c/64 scope global dynamic mngtmpaddr noprefixroute 
       valid_lft 18205sec preferred_lft 18205sec
    inet6 fe80::18a1:fbf4:1e23:5b70/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
```
---

### **Step 2: Assign a Static IP**
The following command assigns a static IP address (192.168.31.100/24) to the interface wlo1:

```bash
dk@dk-Vivobook-ASUS:~$ sudo ip addr add 192.168.31.100/24 dev wlo1
```
---

### **Step 3: Configure Default Gateway**
Set the default gateway for the network using the following command:

```bash
dk@dk-Vivobook-ASUS:~$ sudo ip route add default via 192.168.31.1 dev wlo1
``` 
---

### **Step 4: Verify Configuration**
Check if the static IP has been successfully configured. Below is the updated interface configuration:

```bash
dk@dk-Vivobook-ASUS:~$ ip addr show dev wlo1
2: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
    link/ether a0:59:50:39:af:fd brd ff:ff:ff:ff:ff:ff
    altname wlp0s20f3
    inet 192.168.31.188/24 brd 192.168.31.255 scope global dynamic noprefixroute wlo1
       valid_lft 25969sec preferred_lft 25969sec
    inet 192.168.31.100/24 scope global secondary wlo1
       valid_lft forever preferred_lft forever
    inet6 2409:40f4:111f:c2f2:e28a:eef9:cba0:728c/64 scope global temporary dynamic 
       valid_lft 18171sec preferred_lft 18171sec
    inet6 2409:40f4:111f:c2f2:1d04:21d:1325:fa9c/64 scope global dynamic mngtmpaddr noprefixroute 
       valid_lft 18171sec preferred_lft 18171sec
    inet6 fe80::18a1:fbf4:1e23:5b70/64 scope link noprefixroute 
       valid_lft forever preferred_lft forever
```

---

## **2. Verify Connectivity**

### **Ping the Gateway**
Verify connectivity to the default gateway (192.168.31.1) by using the ping command:

```bash
dk@dk-Vivobook-ASUS:~$ ping 192.168.31.1
PING 192.168.31.1 (192.168.31.1) 56(84) bytes of data.
64 bytes from 192.168.31.1: icmp_seq=1 ttl=64 time=6.74 ms
64 bytes from 192.168.31.1: icmp_seq=2 ttl=64 time=3.99 ms
64 bytes from 192.168.31.1: icmp_seq=3 ttl=64 time=3.10 ms
^C
--- 192.168.31.1 ping statistics ---
3 packets transmitted, 3 received, 0% packet loss, time 2004ms
rtt min/avg/max/mdev = 3.097/4.608/6.739/1.549 ms
```