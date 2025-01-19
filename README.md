# Integrated Inventory Management System

## Description
Design and implement an Integrated Inventory Management System for a factory that includes spare parts and their associated suppliers. The system should leverage various data structures, including linked lists, stacks, queues, and trees, to efficiently manage and organize inventory information.

## Classes Implementation

### SparePart Class
- **Data Members**: 
  - partName
  - partNumber
  - cost
  - existingParts
- **Member Functions**:
  - `getdata()`: Input spare part details
  - `putdata()`: Display spare part data
  - `modifydata()`: Modify spare part information

### Supplier Class
- **Data Members**:
  - supplierName
  - supplierCode
  - address
  - telephone
  - email
- **Member Functions**:
  - `getdata()`: Input supplier details
  - `putdata()`: Display supplier data
  - `modifydata()`: Modify supplier information

## Data Structure for Spare Parts and Suppliers

- Develop a structure for each spare part that includes the group of suppliers providing it.
- Similarly, create a structure for each supplier to express the spare parts they supply.
- Utilize linked lists to establish connections between spare parts and suppliers.

## Search Function
- Implement a function to search for a specific spare part or supplier using binary trees for quick lookups and deletions.

## Implementation Considerations
- Ensure that part numbers and supplier codes are unique to prevent repetition (No Duplicates).
- Use linked lists to dynamically manage lists of spare parts and suppliers.
- Implement stacks for managing user interactions during data input, such as interaction history.
- Use queues for efficiently processing and updating spare part and supplier data.
- Employ trees for organizing, deleting, and searching spare parts and suppliers based on unique identifiers.

## Time Complexity
- Mention the time complexity for each method you implement (e.g., O(N)).

## Main Program
- Create instances of spare parts and suppliers.
- Allow the user to input data for up to 100 spare parts and 20 suppliers.
- Print out the data for both spare parts and suppliers.
- Let the user select the data structure and operation to be performed.

## Bonus
- Implement a graphical user interface (GUI) for this project (optional).
