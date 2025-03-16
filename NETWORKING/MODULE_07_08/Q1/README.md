# **Network Diagnostics Using `ping` and `nslookup`**

## **Objective**
This document explores the use of `ping` (on Ubuntu) and `nslookup` to test connectivity and resolve domain names for the following websites:
- www.google.com  
- www.facebook.com  
- www.amazon.com  
- www.github.com  
- www.cisco.com  

---

## **Tools Used**
- `ping`: Checks network reachability and round-trip time (RTT).  
- `nslookup`: Resolves domain names to IP addresses.  

---

## **Tested Website: www.google.com**
### **1. Ping Results**

### **Google**
```bash
dk@dk-Vivobook-ASUS:~$ ping -c 4 www.google.com
PING www.google.com (2404:6800:4002:81c::2004) 56 data bytes
64 bytes from del11s17-in-x04.1e100.net (2404:6800:4002:81c::2004): icmp_seq=1 ttl=57 time=95.3 ms
64 bytes from del11s17-in-x04.1e100.net (2404:6800:4002:81c::2004): icmp_seq=2 ttl=57 time=95.1 ms
64 bytes from del11s17-in-x04.1e100.net (2404:6800:4002:81c::2004): icmp_seq=3 ttl=57 time=92.1 ms
64 bytes from del11s17-in-x04.1e100.net (2404:6800:4002:81c::2004): icmp_seq=4 ttl=57 time=91.2 ms

--- www.google.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3003ms
rtt min/avg/max/mdev = 91.249/93.432/95.307/1.793 ms
```
### **Facebook**
```bash
dk@dk-Vivobook-ASUS:~$ ping -c 4 www.facebook.com
PING www.facebook.com (2a03:2880:f137:182:face:b00c:0:25de) 56 data bytes
64 bytes from edge-star-mini6-shv-02-maa2.facebook.com (2a03:2880:f137:182:face:b00c:0:25de): icmp_seq=1 ttl=55 time=36.5 ms
64 bytes from edge-star-mini6-shv-02-maa2.facebook.com (2a03:2880:f137:182:face:b00c:0:25de): icmp_seq=2 ttl=55 time=41.7 ms
64 bytes from edge-star-mini6-shv-02-maa2.facebook.com (2a03:2880:f137:182:face:b00c:0:25de): icmp_seq=3 ttl=55 time=44.4 ms
64 bytes from edge-star-mini6-shv-02-maa2.facebook.com (2a03:2880:f137:182:face:b00c:0:25de): icmp_seq=4 ttl=55 time=36.7 ms

--- www.facebook.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3005ms
rtt min/avg/max/mdev = 36.481/39.794/44.366/3.363 ms
```
### **Amazon**
```bash
dk@dk-Vivobook-ASUS:~$ ping -c 4 www.amazon.com
PING www.amazon.com (2600:9000:2354:a400:7:49a5:5fd4:b121) 56 data bytes
64 bytes from 2600:9000:2354:a400:7:49a5:5fd4:b121: icmp_seq=1 ttl=56 time=34.0 ms
64 bytes from 2600:9000:2354:a400:7:49a5:5fd4:b121: icmp_seq=2 ttl=56 time=36.6 ms
64 bytes from 2600:9000:2354:a400:7:49a5:5fd4:b121: icmp_seq=3 ttl=56 time=35.4 ms
64 bytes from 2600:9000:2354:a400:7:49a5:5fd4:b121: icmp_seq=4 ttl=56 time=54.0 ms

--- www.amazon.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3006ms
rtt min/avg/max/mdev = 34.001/39.999/54.000/8.135 ms
```
### **Github**
```bash
dk@dk-Vivobook-ASUS:~$ ping -c 4 www.github.com
PING github.com (20.207.73.82) 56(84) bytes of data.
64 bytes from 20.207.73.82: icmp_seq=1 ttl=112 time=67.9 ms
64 bytes from 20.207.73.82: icmp_seq=2 ttl=112 time=52.4 ms
64 bytes from 20.207.73.82: icmp_seq=3 ttl=112 time=54.6 ms
64 bytes from 20.207.73.82: icmp_seq=4 ttl=112 time=51.9 ms

--- github.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3003ms
rtt min/avg/max/mdev = 51.881/56.699/67.947/6.571 ms
```
### **Cisco**
```bash
dk@dk-Vivobook-ASUS:~$ ping -c 4 www.cisco.com
PING www.cisco.com (2600:140f:6:1a7::b33) 56 data bytes
64 bytes from g2600-140f-0006-01a7-0000-0000-0000-0b33.deploy.static.akamaitechnologies.com (2600:140f:6:1a7::b33): icmp_seq=1 ttl=57 time=43.7 ms
64 bytes from g2600-140f-0006-01a7-0000-0000-0000-0b33.deploy.static.akamaitechnologies.com (2600:140f:6:1a7::b33): icmp_seq=2 ttl=57 time=41.7 ms
64 bytes from g2600-140f-0006-01a7-0000-0000-0000-0b33.deploy.static.akamaitechnologies.com (2600:140f:6:1a7::b33): icmp_seq=3 ttl=57 time=39.8 ms
64 bytes from g2600-140f-0006-01a7-0000-0000-0000-0b33.deploy.static.akamaitechnologies.com (2600:140f:6:1a7::b33): icmp_seq=4 ttl=57 time=38.0 ms

--- www.cisco.com ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3004ms
rtt min/avg/max/mdev = 38.036/40.815/43.706/2.117 ms
```

#### General Observation:
The packets were successfully transmitted and received.

RTT values indicate minimal latency.

---

### **2. nslookup Results**

### **Google**
```bash
dk@dk-Vivobook-ASUS:~$ nslookup www.google.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
Name:	www.google.com
Address: 142.250.183.228
Name:	www.google.com
Address: 2404:6800:4002:81c::2004
```
### **Facebook**
```bash
dk@dk-Vivobook-ASUS:~$ nslookup www.facebook.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
www.facebook.com	canonical name = star-mini.c10r.facebook.com.
Name:	star-mini.c10r.facebook.com
Address: 157.240.23.35
Name:	star-mini.c10r.facebook.com
Address: 2a03:2880:f137:182:face:b00c:0:25de
```
### **Amazon**
```bash
dk@dk-Vivobook-ASUS:~$ nslookup www.amazon.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
www.amazon.com	canonical name = tp.47cf2c8c9-frontier.amazon.com.
tp.47cf2c8c9-frontier.amazon.com	canonical name = d3ag4hukkh62yn.cloudfront.net.
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 108.159.17.235
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:5c00:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:6600:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:5000:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:9800:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:1800:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:a400:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:c400:7:49a5:5fd4:b121
Name:	d3ag4hukkh62yn.cloudfront.net
Address: 2600:9000:2354:7a00:7:49a5:5fd4:b121
```
### **Github**
```bash
dk@dk-Vivobook-ASUS:~$ nslookup www.github.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
www.github.com	canonical name = github.com.
Name:	github.com
Address: 20.207.73.82
```
### **Cisco**
```bash
dk@dk-Vivobook-ASUS:~$ nslookup www.cisco.com
Server:		127.0.0.53
Address:	127.0.0.53#53

Non-authoritative answer:
www.cisco.com	canonical name = www.cisco.com.akadns.net.
www.cisco.com.akadns.net	canonical name = wwwds.cisco.com.edgekey.net.
wwwds.cisco.com.edgekey.net	canonical name = wwwds.cisco.com.edgekey.net.globalredir.akadns.net.
wwwds.cisco.com.edgekey.net.globalredir.akadns.net	canonical name = e2867.dsca.akamaiedge.net.
Name:	e2867.dsca.akamaiedge.net
Address: 23.220.238.70
Name:	e2867.dsca.akamaiedge.net
Address: 2600:140f:6:18a::b33
Name:	e2867.dsca.akamaiedge.net
Address: 2600:140f:6:1a7::b33
```

#### General Observation:
The DNS resolved www.google.com to multiple IP addresses.

The server used was 127.0.0.53, indicating Ubuntu’s systemd-resolved service.

---

### **3. Wireshark capture**

![Capture](1.%20Google.png)

#### Output:
ICMPv6 Packet Capture (Wireshark):

    Source MAC: a0:59:50:39:af:fd (PC)
    Destination MAC: d4:4d:9f:aa:84:7c (Router) [Since MAC are of Layer 2, we could see only the MAC othe router in our network & not of Google's]
    Ping request successfully transmitted and replied.