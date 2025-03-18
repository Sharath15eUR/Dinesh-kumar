# **VLAN Configuration and Inter-VLAN Routing in Packet Tracer**

---

## **1. Verify VLAN Configuration on the Switch**
Ensure that VLAN 10 and VLAN 20 are properly created:

```plaintext
Switch# show vlan brief
```

Confirm that both VLANs exist and that their respective ports are correctly assigned to them.

**Example Output:**

```plaintext
VLAN Name                             Status    Ports
10   VLAN10                           active    Fa0/1, Fa0/2
20   VLAN20                           active    Fa0/3, Fa0/4
```

---

## **2. Check Port Configuration**
Ensure that the ports assigned to VLANs are access ports and belong to the correct VLAN:

```plaintext
Switch# show running-config interface Fa0/1
```

**Example Configuration for Port in VLAN 10:**

```plaintext
interface Fa0/1
switchport mode access
switchport access vlan 10
```

Repeat for ports in VLAN 20.

---

## **3. Understand Why Communication Fails**
Devices in different VLANs cannot communicate directly because VLANs segregate Layer 2 (Data Link Layer) domains. To enable communication between VLANs, you need inter-VLAN routing.

VLANs operate as separate broadcast domains, and without a Layer 3 device (e.g., router or Layer 3 switch), packets cannot traverse VLAN boundaries.

---

## **4. Enable Inter-VLAN Routing**

### **Option 1: Use a Router (Router-on-a-Stick)**
Configure a trunk link between the switch and the router:

**Example for the switch:**

```plaintext
Switch(config)# interface Fa0/24
Switch(config-if)# switchport mode trunk
Switch(config-if)# switchport trunk allowed vlan 10,20
```

Configure subinterfaces on the router for each VLAN:

```plaintext
Router(config)# interface Gig0/0.10
Router(config-subif)# encapsulation dot1q 10
Router(config-subif)# ip address 192.168.10.1 255.255.255.0
Router(config-subif)# exit

Router(config)# interface Gig0/0.20
Router(config-subif)# encapsulation dot1q 20
Router(config-subif)# ip address 192.168.20.1 255.255.255.0
Router(config-subif)# exit
```

Set the default gateway on each PC to point to the router's subinterface IP for their VLAN:

- For VLAN 10 PCs: **192.168.10.1**
- For VLAN 20 PCs: **192.168.20.1**

---

### **Option 2: Use a Layer 3 Switch**
Enable routing on the switch:

```plaintext
Switch(config)# ip routing
```

Configure VLAN interfaces (SVIs) for each VLAN:

```plaintext
Switch(config)# interface vlan 10
Switch(config-if)# ip address 192.168.10.1 255.255.255.0
Switch(config-if)# no shutdown

Switch(config)# interface vlan 20
Switch(config-if)# ip address 192.168.20.1 255.255.255.0
Switch(config-if)# no shutdown
```

Set the default gateway for PCs as the corresponding VLAN interface IP.

---

## **5. Verify Connectivity**
Test communication between devices in VLAN 10 and VLAN 20:

```plaintext
ping 192.168.20.x
```

Ensure PCs have the correct gateway and routing is enabled.

---

## **6. Optional: Check Trunk Link Configuration**
If using trunk links between switches or between the switch and the router, verify the trunk configuration:

```plaintext
Switch# show interfaces trunk
```

---

## **7. Troubleshooting Checklist**
- Ensure VLANs are properly created and ports assigned.

- Confirm trunk configuration (if used).

- Verify inter-VLAN routing is configured correctly (Router or Layer 3 Switch).

- Ensure PCs have the correct default gateway set.

- Use `ping` and `traceroute` to test connectivity and isolate issues.

---

