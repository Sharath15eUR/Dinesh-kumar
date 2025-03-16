# **Capture DNS, TCP, UDP**

## Objective
Use Wireshark to capture and analyze DNS, TCP, and UDP traffic. Focus on observing:
- Packet headers
- Packet flow
- Options
- Flags

---

## **DNS**

## 1. Records, Extensions, and Usage
- **A**: Address record, maps a domain to an IPv4 address.
- **AAAA**: Address record, maps a domain to an IPv6 address.
- **CNAME**: Canonical Name record, maps an alias name to the true or canonical domain name.
- **OPT**: Option record, used to enhance the DNS protocol with additional features, like extended message sizes.

---

## 2. Key Learnings/Inferences from Packets

### Ethernet
- **MAC Address Communication**: Displays source and destination MAC addresses, facilitating communication at the physical layer.
- **Frame Size**: Indicates the size of the Ethernet frame, crucial for data link layer efficiency.
- **Type Field**: Specifies the protocol (e.g., IPv4), allowing proper handling of higher-layer data.

### IPv4
- **Source and Destination IPs**: Essential for routing packets across networks.
- **Protocol Field**: Identifies the transport layer protocol (e.g., UDP in this case).
- **TTL (Time to Live)**: Shows how many hops the packet can take before being dropped, crucial for routing and loop prevention.
- **Header Length**: Defines the size of the IPv4 header, ensuring correct parsing of the packet.
- **Flags (Don’t Fragment)**: Indicates whether packet fragmentation is allowed, aiding in efficient packet handling.

### UDP
- **Connectionless Transmission**: Highlights the lightweight, connectionless nature of UDP for faster communication.
- **Source and Destination Ports**: Indicate the sending and receiving applications, essential for identifying services.
- **Checksum**: Used for error checking, ensuring data integrity.

### DNS
- **Query and Response Process**: Showcases the DNS resolution workflow, including transaction IDs and flags.
- **Flags (Recursion Desired/Available)**: Indicate whether the DNS query should or can be resolved recursively.
- **Questions and Answers**: Includes the domain queried (e.g., `www.youtube.com`) and its resolved IPs.
- **Response Code**: Displays the status of the DNS query, such as "No Error."

---

## 3. Query & Response

![Query](images/1.%20DNS%20query.png)
![Response](images/2.%20DNS%20response.png)

---

## **UDP (Youtube traffic)**

## 1. Protocols, Extensions, and Usage
- **DNS (Domain Name System)**: Resolves domain names to IP addresses and vice versa. Used for connecting to websites and online services.
- **UDP (User Datagram Protocol)**: Lightweight, connectionless transport protocol, prioritizing speed and low latency. Commonly used in DNS queries, video streaming, and gaming.
- **MDNS (Multicast DNS)**: Resolves hostnames to IP addresses within local networks, enabling device discovery (e.g., printers, smart TVs).
- **QUIC (Quick UDP Internet Connections)**: A transport layer protocol built on UDP, designed for secure, low-latency internet communication (e.g., YouTube streaming with HTTP/3).
- **Extensions**:
  - **DNS OPT**: Adds extended functionality to DNS, such as larger message sizes and DNSSEC.

![UDP_general](images/3.%20UDP_general.png)

---

## 2. Key Learnings/Inferences from Packets

### Ethernet
- **MAC Address Communication**:
  - Source: `Skyworthbig_aa:84:7c (4d:4d:9f:aa:84:7c)`
  - Destination: `Intel_39:af:fd (a0:59:50:39:af:fd)`
- **Frame Size**: 1288 bytes on wire (10304 bits).
- **Type Field**: Specifies IPv6 (`0x86dd`).

### IPv6
- **Source and Destination IPs**:
  - Source: `2404:6800:4002:82b::200e`
  - Destination: `2409:40f4:111f:c2f2:c6cf:4f3a:bf3d:4a0b`
- **Traffic Class**:
  - **DSCP**: CS4 (Class Selector 4, high-priority traffic).
  - **ECN**: Not-ECT (Explicit Congestion Notification not enabled).
- **Payload Length**: 1234 bytes.
- **Next Header**: UDP (`17`).
- **Hop Limit**: 58 (remaining hops before the packet is dropped).

### UDP
- **Source Port**: 443 (commonly used for QUIC or HTTPS).
- **Destination Port**: 43400 (dynamic ephemeral port, client-initiated session).
- **Length**: 1234 bytes (UDP header + payload).
- **Checksum**: `0x60da` (unverified).
- **Payload**: 1226 bytes of data.

### Key Insights
- **Connectionless Communication**:
  - UDP provides a lightweight design for faster data transfer without connection setup.
- **QUIC Over UDP**:
  - The presence of **source port 443** indicates secure, high-speed communication via HTTP/3 (QUIC), likely used by YouTube for video streaming.
- **IPv6 Efficiency**:
  - IPv6 ensures seamless routing with a larger address space and more efficient network-layer processing.
- **Prioritization**:
  - The **DSCP: CS4 (high-priority traffic)** hints at optimized performance for latency-sensitive applications like video streaming.

![UDP_youtube](images/4.%20UDP_youtube.png)
![Follow stream](images/5.%20Follow%20stream.png)

---

## 3. Frame Details (From Image)
- **Frame Size**: 1288 bytes on wire (10304 bits).
- **Captured Bytes**: 1288 bytes on interface `wlan0`.
- **Interface ID**: `0`.

---

## 4. Insights
### Query:
- **Source Address**: Cient device (`2409:40f4:111f:c2f2:c6cf:4f3a:bf3d:4a0b`).
- **Destination Address**: A YouTube/Google QUIC server (`2404:6800:4002:82b::200e`).

### Response:
- The server is sending encrypted data back to the client over UDP using QUIC. The payload size of 1226 bytes suggests active data exchange, likely streaming-related.

- The combination of **IPv6**, **port 443**, and **UDP** implies **QUIC** is being used to optimize streaming, reduce latency, and enhance user experience for platforms like YouTube.
- This packet shows **connectionless, encrypted traffic**, ideal for modern web applications requiring fast and secure communication.

---

## TCP 

## 1. TCP Handshake Establishment
I can see the TCP handshake is established between my device and WhatsApp servers using specific ports. Here, port `443` indicates secure HTTPS communication.

![TCP Handshake](images/6.%20TCP.png)

### Inference:
- The **3-way handshake** is confirmed through the presence of packets with SYN, SYN-ACK, and ACK flags.
- Port `443` suggests encrypted data exchange, with TCP establishing the foundation for TLS traffic.

---

## 2. Source and Destination Address
Source and destination IP addresses are clearly visible in the packet headers.

### Inference:
- The source address represents my device, and the destination corresponds to WhatsApp servers.
- Observing these addresses helps confirm the endpoints involved in the communication.

---

## 3. Packet Flow
From the packet flow (TCP stream), I could find data being sent in packets after the handshake is complete.

![Packet Flow](images/7.%20tcp%20stream.png)

### Inference:
- The stream includes TCP packets containing segments of the application-layer data.
- Observing packet flow ensures proper data exchange without retransmissions or dropped packets.

---

## 4. Possible Options in TCP
Possible options present in TCP include:
- **Maximum Segment Size (MSS)**: Defines the largest segment that can be transmitted.
- **SACK Permitted**: Enables selective acknowledgments for efficient retransmission.
- **Timestamps**: Assists in measuring round-trip time (RTT) and improving performance.
- **No-Operation (NOP)**: Acts as a filler to align options.
- **Window Scale**: Expands the TCP window size for better throughput.

### Inference:
- TCP options enhance connection performance and ensure reliable data delivery, particularly in dynamic network conditions.

---

## 5. TCP Flags
TCP flags have separate values to signify specific states:
- `0x02` for SYN: Indicates a synchronization request to initiate a connection.
- `0x10` for ACK: Acknowledges the receipt of data or connection establishment.
- `0x12` for SYN-ACK: Combines synchronization and acknowledgment during the handshake.

### Inference:
- Each flag plays a critical role in managing connection states and ensuring reliable communication.


