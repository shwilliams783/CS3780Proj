# CS3780Proj
Password Encryption Demonstration

# CS3780
Programming Project 1
Due date: November 28th, 2017
# Overview:
In this project you will be working with a crypto library, in particular openssl on the student
server delmar at delmar.umsl.edu. You will be writing a program that creates several password
files and then attempts to see how hard they are to crack.
# Task 1:
This task is primarily useful for allowing us to verify everything is working for other tasks, but is
also an exercise in learning about using crypto libraries and the different ways of storing
passwords.
The first program you should write is one that gives the user two options:
1) Creating an account
2) Authenticating that account
When the user wants to create an account, you should ask them for their username and a
password. This password should be restricted to just numbers (yes, not secure, but will make
cracking much more scalable). You should then store that authentication information in 3
separate password files.
One file, called passwdmd5, should store the list of usernames and their associated md5 hash of
their passwd
Another file, called passwdSHA256, should store the list of usernames and their associated
sha256 hash of their passwd
Lastly, another file, called passwdSHA256salt, should store the list of usernames and their
associated SHA256 hash of their passwd, along with a cryptographically random salt value. Let
us just use 4 bytes of salt value for this.
When the user tries to authenticate an account, you should prompt them for username and
password. Then you should check that data against the appropriate passwd files and see if a
match exists. For testing purposes, please display the results of all 3 matches against usernames,
indicating hash produced and hash that was stored in the file.
# Task 2:
Write a program to fill up the appropriate password files with random passwords of a given
length for incremented users. For example, if we wanted to generate random passwords of length
3 (note again only numeric passwords), the passwords would be rrr, rrr, rrr, rrr associated with
username000, username001, username002 and so on. Note that these rrr’s would be different for
each user. This program should be able to be run by the command line, so for example…
./fillWithRandomUsers 3 100
and it would fill one passwd file with
username000 and md5(rrr)
…
username100 and md5(rrr)
then
username000 and SHA256(rrr)
…
username100 and SHA256(rrr)
then
username000 and salt and SHA256(rrr + salt)
…
username100 and salt and SHA256(rrr + salt)
# Task 3:
Write a program that will attempt to crack a passwd file. That is, if given a password file, it will
load the data from the file into some data structures and then try and figure out one of the
passwords by brute-forcing possible passwords and trying to authenticate them.
This should be runnable on the command line, with something like
./crackIt 0 3 passwdmd5
which would start trying to brute-force passwords of size 3 using the md5 hashing against the file
passwdmd5. Once a match is found, it should be displayed and the time it spent to find it should
also be displayed.
# Task 4:
Experiment with the programs generated in task 2 and task 3 and write up your results. Find out
how it scales as password size increases. Note that I am not expecting you to try and make this
too efficient. That would be an entire course in and of itself (faster lookup of hash matches, etc).
I am looking for comparative results between the methods. These results should be in a file
called README, raw text, submitted with your files.
# Setting up your environment:
First, download openssl at the following link (Version 1.1)
https://www.openssl.org/source/
Then put it on delmar.umsl.edu , extract the file
Now you need to configure it before installation
./config --prefix=$HOME/usr/local/ssl
to put openssl in usr/local/ssl or some other directory that you want to use.
Now you need to compile it. To do this type
make
Lastly, install it:
make install
Now it is necessary to change the LD_LIBRARY_PATH environment variable to point to the
shared libraries. To do this, add two lines to your .bash_profile file in your home directory
(modifying it with your appropriate starting location, which you can get with pwd):
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/accounts/facstaff/hauschildm/usr/local/ssl/lib
export LD_LIBRARY_PATH
Log out and back in to your shell when this is done.
To get you started on just using a hash that is available, I have put a very simple test program in
the following location, along with a simple makefile that should work if you have followed the
suggestions above:
/accounts/facstaff/hauschildm/SS/proj1test
If everything was done correctly, you should be able to type:
make
and then run it with
./ssfun
# Resources:
https://wiki.openssl.org/index.php/Compilation_and_Installation
It is reasonable to expect some possible issues when installing. So make sure and do this early
and not wait too long.
# Submission:
Submission guidelines will follow. I will expect all sources, appropriate README and makefile
to be available. I am considering setting up appointments for project demonstrations during final
exams week.
