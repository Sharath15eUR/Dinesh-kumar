# **Task: Identify IP Address Classes and Provide Details**

## **Objective**
1. Identify the class of the given IP addresses.
2. Determine the default subnet mask for each class.
3. Provide the range of IP addresses for each class.

---

## **1. Given IP Addresses**
- **10.1.1.1**
- **172.16.5.10**
- **192.168.1.5**

---

## **2. Explanation of IP Address Classes**
### **Classes of IP Addresses**:
- **Class A**:
  - First octet range: `1 - 126`.
  - Default Subnet Mask: `255.0.0.0`.
  - Address Range: `1.0.0.0` to `126.255.255.255`.
  - Used for: Very large networks.

- **Class B**:
  - First octet range: `128 - 191`.
  - Default Subnet Mask: `255.255.0.0`.
  - Address Range: `128.0.0.0` to `191.255.255.255`.
  - Used for: Medium-sized networks.

- **Class C**:
  - First octet range: `192 - 223`.
  - Default Subnet Mask: `255.255.255.0`.
  - Address Range: `192.0.0.0` to `223.255.255.255`.
  - Used for: Small networks.

---

## **3. Classifications of the Given IP Addresses**

| **IP Address**  | **Class** | **Default Subnet Mask** | **IP Address Range**       |
|------------------|-----------|-------------------------|-----------------------------|
| `10.1.1.1`       | Class A   | `255.0.0.0`            | `1.0.0.0 - 126.255.255.255` |
| `172.16.5.10`    | Class B   | `255.255.0.0`          | `128.0.0.0 - 191.255.255.255`|
| `192.168.1.5`    | Class C   | `255.255.255.0`        | `192.0.0.0 - 223.255.255.255`|



