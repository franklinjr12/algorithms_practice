#
# Simple linked list with loose end (final node points to NULL).
# Todo:
# Add node to list (OK)
# Print list (OK)
# Remove node from list ()
# Count number of elements ()
# Sort list by id ()
#


class Ll_node:
    
    def __init__(self, id):
        print("ll_node constructor")
        self.id = id
        self.next = None
        self.sp = None

    def print(self):
        err = 0
        print(self.id)
        if (self.next == None):
            return err
        next = self.next
        while (next != None):
            print(next.id)
            next = next.next
        return err
    
    def add(self, n):        
        if (n == None):
            return -1
        err = 0
        if (self.next == None):
            self.next = n
            return err
        next = self.next
        while (next.next != None):
            next = next.next
        next.next = n
        return err
    

def main():
    print("Hello")
    n1 = Ll_node(0)    
    n1.print()
    n2 = Ll_node(1)
    n1.add(n2)
    n1.print()
    n3 = Ll_node(2)
    n2.add(n3)
    n1.print()

if __name__=="__main__":
    main()