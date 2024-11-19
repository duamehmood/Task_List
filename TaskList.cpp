

/* ***--------------------------------------------***
       FINAL PROJECT : TO - DO - LIST (TASK LIST)
         NAME : DUA MEHMOOD
         ROLL NO : S23BDOCS1M01074 ( BSCS-2M )
         SEMESTER : THIRD (3RD)
   ***--------------------------------------------*** */

#include <iostream>
using namespace std;

class task
{

private:
    int id;
    string name;
    string description;
    string priority;
    string catagorey;
    string status;

public:
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getDescription()
    {
        return description;
    }
    void setDescription(string description)
    {
        this->description = description;
    }
    string getPriority()
    {
        return priority;
    }
    void setPriority(string priority)
    {
        this->priority = priority;
    }
    string getCatagorey()
    {
        return catagorey;
    }
    void setCatagoery(string catagorey)
    {
        this->catagorey = catagorey;
    }
    string getStatus()
    {
        return status;
    }
    void setStatus(string status)
    {
        this->status = status;
    }
};

class node
{

private:
    node *previous;
    node *next;

public:
    task detail;
    node *getPrevious()
    {
        return previous;
    }
    void setPrevious(node *previous)
    {
        this->previous = previous;
    }
    node *getNext()
    {
        return next;
    }
    void setNext(node *next)
    {
        this->next = next;
    }
    void setTaskDetails(int id, string name, string description, string priority, string catagorey, string status)
    {
        this->detail.setId(id);
        this->detail.setName(name);
        this->detail.setDescription(description);
        this->detail.setPriority(priority);
        this->detail.setCatagoery(catagorey);
        this->detail.setStatus(status);
    }
    string getTaskDetails()
    {
        string data = "ID: " + to_string(this->detail.getId()) + "\n Name: " + this->detail.getName() + "\n Description: " + this->detail.getDescription() + "\n Status: " + this->detail.getStatus() + "\n Priority: " + this->detail.getPriority() + "\n Catagorey: " + this->detail.getCatagorey();
        return data;
    }
};

class list
{

    node *head;
    node *curr;
    int size;

public:
    list()
    {
        head = new node();
        head->setNext(NULL);
        head->setPrevious(NULL);
        curr = head;
        size = 0;
    }

    int length()
    {
        return size;
    }

    void insert(int id, string name, string description, string priority, string catagorey, string status)
    {
        node *n = new node();
        n->setTaskDetails(id, name, description, priority, catagorey, status);
        n->setNext(curr->getNext());

        if (curr->getNext() != NULL)
        {
            curr->getNext()->setPrevious(n);
        }
        n->setPrevious(curr);
        curr->setNext(n);
        n->setPrevious(curr);
        curr = n;
        size++;
        cout << "Task Added Successfully \n";
        cout << "\n-----------------------------\n"
             << endl;
    }

    void remove(int id)
    {
        node *temp = head->getNext();
        int found = 0;
        while (temp != NULL)
        {
            if (temp->detail.getId() == id)
            {
                found = 1;
                break;
            }
            else
            {
                temp = temp->getNext();
            }
        }
        if (found == 1)
        {
            curr = temp;
            if (size != 0 && curr->getNext() != NULL)
            {
                curr->getPrevious()->setNext(curr->getNext());
                curr->getNext()->setPrevious(curr->getPrevious());
                size--;
            }
            else if (size != 0 && curr->getNext() == NULL)
            {
                curr->getPrevious()->setNext(NULL);
                size--;
            }
            cout << "Task with ID " << id << " removed\n";
        }
        else
        {
            cout << "Task with ID " << id << " not found\n";
        }
        curr = head->getNext() == NULL ? head : head->getNext();
    }

    void changeStatus(int id, string newStatus)
    {
        node *temp = head->getNext();
        while (temp != NULL)
        {
            if (temp->detail.getId() == id)
            {
                temp->detail.setStatus(newStatus);
                cout << "Status of Task with ID " << id << " changed to " << newStatus << endl;
                return;
            }
            temp = temp->getNext();
        }
        cout << "Task with ID " << id << " not found" << endl;
    }

    void priority(string a)
    {
        if (a == "High" || a == "high")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getPriority() == "High" || temp->detail.getPriority() == "high")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }

        else if (a == "Moderate" || a == "moderate")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getPriority() == "Moderate" || temp->detail.getPriority() == "moderate")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else if (a == "Low" || a == "low")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getPriority() == "Low" || temp->detail.getPriority() == "low")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else
        {
            cout << "Invalid Input (please enter High,Modertae or Low)" << endl;
        }
    }

    void status(string s)
    {

        if (s == "Complete" || s == "complete")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getStatus() == "Complete" || temp->detail.getStatus() == "complete")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else if (s == "Pending" || s == "pending")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getStatus() == "Pending" || temp->detail.getStatus() == "pending")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else
        {
            cout << "Invalid option..!" << endl;
        }
    }

    void category(string c)
    {

        if (c == "Work" || c == "work")
        {
            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getCatagorey() == "Work" || temp->detail.getCatagorey() == "work")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else if (c == "Personal" || c == "personal")
        {

            node *temp = head->getNext();
            while (temp != NULL)
            {
                if (temp->detail.getCatagorey() == "Personal" || temp->detail.getCatagorey() == "personal")
                {

                    cout << temp->getTaskDetails();
                }
                temp = temp->getNext();
            }
        }
        else
        {
            cout << "Invalid Option...!" << endl;
        }
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "\n------------------\n"
                 << endl;
            cout << " Tasks to Do: " << endl;
            cout << "\n------------------\n"
                 << endl;
            node *temp = head;
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
                cout << temp->getTaskDetails() << "\n-----------------------------\n"
                     << endl;
            }
        }
    }

    void printActions()
    {
        cout << "\n-----------------------------\n"
             << endl;
        cout << "Select one of following option: \n"
             << endl;

        cout << "1. Add a Task." << endl;
        cout << "2. Remove Task. " << endl;
        cout << "3. View Tasks. " << endl;
        cout << "4. Change Task Status. " << endl;
        cout << "5. Priority-wise Task Details: " << endl;
        cout << "6. Category-wise Task Details: " << endl;
        cout << "7. Status-wise Task Details: " << endl;
        cout << "8. Check size of Task List: " << endl;
        cout << "0. Exit..." << endl;
        cout << "Enter the Number of your choice: \n-----------------------------\n"
             << endl;
    }
};

int main()
{
    list task;

    while (true)
    {
        int choice;
        task.printActions();

        cin >> choice;

        if (choice == 1)
        {
            int id;
            string name;
            string description;
            string priority;
            string catagorey;
            string status;

            cout << "Enter Task ID: " << endl;
            cin >> id;
            cout << "Enter Task Name: " << endl;
            cin >> name;
            cout << "Enter Task Description: " << endl;
            cin >> description;
            cout << "Select Task Priority (High , Moderate or Low): " << endl;
            cin >> priority;
            cout << "Enter Task Catagorey (Work , Personal): " << endl;
            cin >> catagorey;
            cout << "Enter Task Status (Complete , Pending): " << endl;
            cin >> status;
            task.insert(id, name, description, priority, catagorey, status);
        }

        else if (choice == 2)
        {
            int id;
            cout << "Enter Task ID You want to Remove: " << endl;
            cin >> id;
            task.remove(id);
            cout << "The ID You Entered is Deleted Successfully...! \n"
                 << endl;
            cout << "\n-----------------------------\n"
                 << endl;
        }

        else if (choice == 3)
        {
            task.display();
        }
        else if (choice == 4)
        {
            int id;
            string newStatus;
            cout << "Enter Task ID for which you want to change status: " << endl;
            cin >> id;
            cout << "Enter new status: " << endl;
            cin >> newStatus;
            task.changeStatus(id, newStatus);
            cout << "Task Status is Updated Successfully...! \n"
                 << endl;
            cout << "\n-----------------------------\n"
                 << endl;
        }

        else if (choice == 5)
        {
            int prioritySelection;

            cout << "Enter the Priority Level of Task You want to see Details about: \n 1.High \n 2.Moderate \n 3.Low " << endl;
            cin >> prioritySelection;

            if (prioritySelection == 1)
            {
                cout << "Highly Prioritized Tasks: \n"
                     << endl;
                task.priority("High");
            }
            else if (prioritySelection == 2)
            {
                cout << "Moderately Prioritized Tasks: \n"
                     << endl;
                task.priority("Moderate");
            }
            else if (prioritySelection == 3)
            {
                cout << "Low Prioritized Tasks: \n"
                     << endl;
                task.priority("Low");
            }
            else
            {
                cout << "choice Not Available Enter Right one..." << endl;
            }
        }

        else if (choice == 6)
        {
            int categorySelection;

            cout << "Enter the category of Task You want to see Details about: \n 1.Work \n 2.Personal " << endl;
            cin >> categorySelection;

            if (categorySelection == 1)
            {
                cout << "Tasks from Workplace: \n"
                     << endl;
                task.category("Work");
            }
            else if (categorySelection == 2)
            {
                cout << "Personal Tasks: \n"
                     << endl;
                task.category("Personal");
            }
            else
            {
                cout << "Entered category is not Available...! " << endl;
            }
        }

        else if (choice == 7)
        {
            int statusSelection;

            cout << "Enter the Status of Task You want to see Details about: \n 1.Complete \n 2.Pending " << endl;
            cin >> statusSelection;

            if (statusSelection == 1)
            {
                cout << "Completed Tasks: \n"
                     << endl;
                task.status("Complete");
            }
            else if (statusSelection == 2)
            {
                cout << "Pending Tasks: \n"
                     << endl;
                task.status("Pending");
            }
            else
            {
                cout << "Invalid Option..." << endl;
            }
        }

        else if (choice == 8)
        {
            cout << "The length of Tasks present in List is: " << task.length() << endl;
        }

        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Invalid Option..." << endl;
        }
    }
}
