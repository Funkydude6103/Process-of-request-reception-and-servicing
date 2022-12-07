# Process-of-request-reception-and-servicing
write a loop that simulates this process of request reception and servicing
and shows how the queues grow longer and shorter.
First ask the user to provide 5 ‘servicing rates’ for the 5 resources. For example,
if the user provides 250 for resource 1, this means that resource 1 services its
request after every 250 milliseconds, i.e. after every 250 milliseconds it
removes a request from the front of its queue sqn[1]. Based on these servicing
rates you should remove a request from the respective queue, shortening it.
Meanwhile, you should add a new request with a random reqid to a
random resource id (between 0 and 5) after every 500 milliseconds (this
addition rate is fixed).
Use the printQueues method to show the status of all queues after every 250
milliseconds. Do this by clearing the screen each time and printing the queues
at the top left of the screen.
