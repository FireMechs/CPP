 #  CPP projects
##  Basic cpp projects
This is a basic cpp projects
<<<<<<< HEAD
## Students Management system(SMS)
File list
* SMS.cpp ( contains the source code for the project)
* studentsData.txt ( contains the students' data )
This project implements the following features
* Admissions ( taking in and storing students data)
* Exams (  Taking in and storing students marks)
        ( Ranking students )
* Details ( search the students list )
* Edit ( edit the students list)
=======
##    Students Management system(SMS)
>>>>>>> 7fcebd370fd7677c9f6fe95651a7d8df0138b547

File  list
 
*  SMS.cpp { contains the source code for the whole project }
*  studentsData.txt { contains the  students' data from the program }


The projects sees  to implement the following features.


* Admissions - taking in students details  and saving the data in a file.
* Exams      - Add to the admission file the students exam score.
		     - Rank students based on the average marks.
* Details - search students database and  show their details.
*  Edit   - delete or change student's details from the system.


__Anyone can fork the repo and contribute to the project__

   
___Follow the following  procedure to setup  a local repo and contribute to the project___

####  Make sure to have git installed on your system

    
* create and setup a local copy of the online repository offline
* fork the repository online 

```bash 
git clone <repo_link>  #clone the repo offline
 ```
```bash
cd repo  #change into the repo
  ```
* create a new remote that points to the original project

```bash
git remote add upstream  <repo_link>
```

* ensure  that you are on   master branch

```bash
git checkout master
```
* sync your local  copy  with the upstream project

```bash 
git pull upstream master
```

* sync to  your forked repository

```bash
git push origin master
```
* create  a branch
  
```bash
git checkout -b <branch_name>
```
* push a new branch 
      
```bash
git push -u origin  <branch_name>
```
 
