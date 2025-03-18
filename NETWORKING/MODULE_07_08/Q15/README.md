# iPerf3 Network Performance Testing

## **Step 1: Start the iPerf Server**
Run the following command in **Terminal 1**:
```bash
iperf3 -s
```
---
## **Step 2: Run the iPerf Client**
Run different tests on **Terminal 2**:

1. Basic TCP Test (Localhost)
```bash
iperf3 -c 127.0.0.1
```
Tests basic TCP bandwidth.

---
2. UDP Test
```bash
iperf3 -u -c 127.0.0.1 -b 10M
```
Tests UDP bandwidth with a 10 Mbps limit.

---

3. Bidirectional Test
```bash
iperf3 -c 127.0.0.1 --bidir
```
Sends data in both directions simultaneously.

---

4. Reverse Test (Server Sends Data to Client)
```bash
iperf3 -c 127.0.0.1 -R
```
Tests data transfer in the reverse direction.

---

5. Parallel Streams (Increase Load)
```bash
iperf3 -c 127.0.0.1 -P 5
```
Runs 5 parallel connections to simulate load.

---

6. Testing with Delay, Jitter, and Loss (UDP)
```bash
iperf3 -u -c 127.0.0.1 -b 10M -t 10
```
Runs for 10 seconds, analyzing jitter and packet loss.

---