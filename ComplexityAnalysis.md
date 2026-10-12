Campus Resource Reservation System
 Complexity Analysis - Project 1 


Linear Search — O(n)

The system uses linear search to find a resource by its ID. The algorithm checks each resource individually until it finds the matching ID or reaches the end of the resource list.

In the worst case, the requested resource is at the end of the list or does not exist. Therefore, the time complexity is O(n), where n is the number of resources.

Merge Sort — O(n log n)

The system uses merge sort to organize resources alphabetically by name. Merge sort repeatedly divides the resource list into smaller sections until each section contains one element. It then merges the sections back together in sorted order.

Dividing the list creates approximately log n levels, and merging all elements at each level takes O(n) time.

Therefore, merge sort has a time complexity of O(n log n) in the best, average, and worst cases.

Active Reservations Report — O(n)

The system displays active reservations by traversing the reservation linked list. Each reservation must be visited once to display its information.

Therefore, displaying all active reservations has a time complexity of O(n), where n is the number of active reservations.

Waiting-List Statistics — O(r + w)

The waiting-list statistics report displays the number of students waiting for each resource.

Assuming the system visits each resource and its waiting students once, the time complexity is O(r + w), where r is the number of resources and w is the total number of waiting students.

Resource Utilization — O(r × n)

The resource utilization report determines how many active reservations are associated with each resource.

If the implementation checks all n active reservations for each of the r resources, the time complexity is O(r × n).

Most Requested Resources — O(r²)

The most-requested-resources report ranks resources using selection sort based on their request counts.

Selection sort repeatedly searches the remaining resources to find the next highest request count. This requires approximately r² comparisons.

Therefore, the time complexity is O(r²), where r is the number of resources.
