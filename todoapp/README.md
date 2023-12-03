# TODOAPP
# VIDEO DEMO: <https://youtu.be/6x0pw_5_UqQ>
# DESCRIPTION:
ToDo app is a comprehensive web application designed to help users organize their daily tasks, as well as keep track of completed tasks.
The application provides an intuitive interface.

## SCREENSHOTS:
![Planning](/static/planning_screenshort.png)
![DailyAgenda](/static/agenda_screenshort.png)
![Completed](/static/completed_screenshort.png)
![Login](/static/login_screenshort.png)
![Register](/static/register_screenshort.png)

## GETTING STARTED
-**PREREQUISITES**
Ensure you have the necessary dependencies installed:
- Python
- Flask
- Bootstrap
- SQLite (or another preferred database)

-**Installation**
1. Navigate progect directory

'''bash
cd todoapp
'''

2. Install dependencies:

'''bash
pip instal -r requirements.txt
'''

-**Usage**

Start the Flask application:
'''bash
flask run


### FEATURES:

#### PLANNING:
The Planning section serves as starting point for users to initiate their planning process.
At the top of the screen, a user-friendly form allows users to seamlessly add new tasks to
their list. This form collects various details about the task, includding:

- **Category:** Represents a broader goal that ecompasses several tasks.
- **Task Name:** Describes the specific task.
- **Priority:** Indicates the priority of the task.
- **Timeframe:** Users can specify a preffered time range and the day of the week when they
have time to complete the task.
- **Date:** If the task if a scheduled event, users can input the date
- **Time:** If the task if a scheduled event, users can input the time

- **Completeon status:**
All added tasks are displayed in a list within a table. For each task there is a checkbox on
the left for marking completion. When a task is marked as completed, it automatically disappears
from the list. Users can reviev their completed tasks in the "Completed" tab.

- **Delete task**
On the right side of each task, there is a delete button. Clicking this button triggers a pop-up
window, confirming whether the user wishes to delete the task. If confirmed, the task is promptly
removed from the list.


#### AGENDA:
The Agenda section serves as a dedicated space for users to view their scheduled meetings and
appointments. Also it provides a focused perspective of the tasks that the user mentioned as
high priority tasks. So that user can concentrate on the most important tasks.

The Agenda is divided into two main categories: "Scheduled Meetings and Appointments" and
"Weekly tasks". Each category is presented in a table format for clarity and ease of use.

-**Scheduled Meetings and Appointments:**
This section lists tasks that are time-specific, such as meetings or appointments. Each task
is assosiated with a category. Users can mark these tasks as completed using the provided
checkboxes and can delete them when necesary.

-**Weekly Tasks:**
The Weekly tasks section is futher divided into two subcategories: Weekdays and Weekends.
It displays tasks that the user marked as high priority tasks. The tasks that the user
wants to concentrate on now. Users can manage these tasks similarly to the scheduled events,
utilizing checkboxes for completion and a delete button for removal.


#### COMPLETED:
The Completed section provides users a retrospective view of tasks that habe been successfully
accomplished. Tasks that were marked as completed from the Planning or Agenda sections are
automatically moved to this dedicated area.

The central component of the Completed section is a table displaying the tasks. Each completed task
is shown with a strikethrough effect on its name, providing a visual cue of its accomplished status.
Additionally, a checkbox is displayed on the left side of each completed task, mirroring the
functionality in the Planning and Agenda sections. This checkbox, when checked, offers users the
ability to revert a task to active task list if needed.

Similar to the Planning and Agenda sections, a delete button is available on the right side of each
completed task. Clicking this button removes the completed task from the records without the pop-up
window.

#### USER AUTHENTICATION AND REGISTRATION
The application includes user authentication functionalities with the following features:
login, logout, and user registration.

**Login**
The Login page provides a simple form where users can input their username and password to access
their personalized TODO list. Upon successful login, users are directed to the Planning section,
where they can start organizing their tasks.

**Logout**
The logout option allows users to securely sign out their accounts. This action clears the user's
session, ensuring the protection of personal information and preventing anauthorized access.

**Register**
The registration page allows new users to create an account by providing a unique username and a
secure password. The registration form includes password strength rewuirements, ensuring users
create robust and secure passwords.


##### DATABASE STRUCTURE
The application employs a SQL database to store and manage user data and task information.
The tables are designed to facilitate efficient data retrieval and storage.

**UserTable**

-**user_id** Unique identifier for each user
-**username** User's chosen name
-**hashed_password** Securely stored hashed password.

**TaskTable**

-**task_id** Unique identifier for each task
-**user_id** Foreign key linking tasks to their respective users
-**category** Category of the task (goal category)
-**task** Description of the task
-**date** Date (if a completion of the task is scheduled)
-**time** Time (if a completion of the task is scheduled)
-**Priority** Priority level of the task
-**Completion** Completion status of the task

This structured database layout ensures data integrity, allowing the application to effectively
manage user-specific tasks and related details



