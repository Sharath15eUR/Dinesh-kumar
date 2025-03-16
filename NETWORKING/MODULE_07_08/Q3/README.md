# Traceroute Analysis and Exploration

## Objective
This document explores the use of the `traceroute` command to analyze network paths to different websites. It delves into interpreting the parameters in the output and investigating the various options available in the `traceroute` command.

---

## Experiment: Tracerouting Google

### Command Used:
```bash
dk@dk-Vivobook-ASUS:~$ traceroute www.google.com
traceroute to www.google.com (142.250.195.68), 30 hops max, 60 byte packets
 1  jiofiber.local.html (192.168.31.1)  188.917 ms  188.447 ms  189.135 ms
 2  192.0.0.1 (192.0.0.1)  382.339 ms  384.169 ms  387.229 ms
 3  192.0.0.1 (192.0.0.1)  403.938 ms  416.361 ms  416.335 ms
 4  192.0.0.1 (192.0.0.1)  416.310 ms  416.539 ms  423.607 ms
 5  192.0.0.1 (192.0.0.1)  424.616 ms  424.119 ms  424.046 ms
 6  192.168.225.103 (192.168.225.103)  429.250 ms  241.246 ms  38.441 ms
 7  192.168.83.24 (192.168.83.24)  33.962 ms  33.648 ms 192.168.83.26 (192.168.83.26)  39.135 ms
 8  * * *
 9  * * *
10  74.125.50.202 (74.125.50.202)  33.791 ms *  39.599 ms
11  * * *
12  maa03s38-in-f4.1e100.net (142.250.195.68)  45.167 ms 142.251.55.230 (142.251.55.230)  38.352 ms 142.250.235.104 (142.250.235.104)  43.489 ms
```

---

## Observations and Inferences

### Destination
The final destination is `www.google.com` with IP address `142.250.195.68`.

### Hops
- The route consists of up to 30 hops (default maximum).
- The listed hops show the intermediary routers the packets traverse.
- For example, hop 1 is `jiofiber.local.html (192.168.31.1)`.

### Latency
- Each hop lists three latency measurements in milliseconds (ms). This measures the round-trip time to each router.
- Example: Hop 1 shows latencies `188.917 ms`, `188.447 ms`, and `189.135 ms`.

### Starred Entries
- `* * *` indicates that the corresponding hop did not respond in time, leading to unknown latencies (possibly blocked or filtered ICMP responses).

### Final Hop
The last entry connects to `maa03s38-in-f4.1e100.net` (Google server) with latencies around `45 ms`.

---

## Exploring Traceroute Command Options
The traceroute command provides additional flexibility through various options:

### Modify Maximum Hops:

Use -m <value> to change the maximum number of hops.

```bash
traceroute -m 20 www.google.com
```
### Use Different Protocols:

Specify UDP, TCP, or ICMP using -P <protocol>.

```bash
traceroute -P TCP www.google.com
```

### Source Address:

Use -s <source> to define the source IP or interface.

```bash
traceroute -s 192.168.1.10 www.google.com
```

### Change Packet Size:

Use -q <queries> to set the number of queries per hop.

```bash
traceroute -q 5 www.google.com
```