
# Lab 1: Introduction to Linux

## Tasks
- Create a file name file1 using terminal; write some text in this file. Create another file name
file2, copy the text from file1 to file2, using terminal. (Write set of commands which you
will use to perform these steps).
- Open the firefox, terminate the firefox process using terminal
- Create directory dir1, place a file named file1. Create another directory dir2, place file
name file2 in it. Move file2 to dir1.
- Compress the dir1 and dir2 in a zip file using terminal, named zipped_directories.
- Unzip the compressed file “zipped_directories” in /home/Labs/Documents
- find out what the following script file does:
CS330: Operating Systems Page 5
- Execute the Following Code(commands.sh)
```bash
#!/bin/bash
echo "hello world"
for f in *.txt; do
f2=${f%%.*}
echo filename $f2
cat $f | sed 's/(.*)//g' > ${f2}_modified.txt
done
```
- Hint: text files contain strings like "aad(bbb)c c"
- make this script file executable by command
chmod u=rwx commands.sh

### Task 1
The command "touch" is used to create a file
```bash
$ touch file1.txt
```  
![](https://lh5.googleusercontent.com/kjDQE-2DHQjigPIKVy4ovnMP9BmyxNyLdvthwE2dNqDMlKBXmpV0sV23NZrDE5hwGhciAp2N7R9JRW2vorq83nB6HOW-VJ6aj7pLhaZ3apokp_IUZctWh3OANcEsWhG3iFLEOTfDfWG-vTLsCQ)

"echo "sometext" >> filename.ext" is used to insert some text in the file
```bash
$ echo "Hello, This is the Task 1 of the Lab 1" >> file1.txt
```

![](https://lh3.googleusercontent.com/IHqRfrVbsNQmu-SimiNIuIph5BF1OSi6TxrwMOEXzpTqXe7sauP8394ewn6tEKoEieTJPHe6ye_Kb0E2mppvXurmgPgdBNV1TGCSQ-dD0Ww9Q-KZBKGKvgDNKsofrCerPPd4WUO6GGkJrYsnpQ)

The following command makes another text file named file2
```bash
$ touch file2.txt
```
To Copy the content of the file into another file we use the "cat file1 > file2" or "cp file1 file2"
```bash
$ cat file1.txt > file2.txt
```  
![](https://lh5.googleusercontent.com/kNAUkYDgikeu2T3w1q5u4LkRKRY1jIfxyqaCLNcG0bQhiIX5igBUAI8NTVRK8Xz8u-GS97d2oQVOoHYjQ0eB5zXQBLnZTZVV6ZyH4AYgJj4oQtXQ_5rYvhowB9WOoC-CaU-UAMyr1IgWxc3Lxw)
### Task 2
To open firefox we use write “firefox &” and it shows us the process ID of the process like in this case the process ID is 25559
```bash
$ firefox &  
[1] 25559
```
To show the currently running tasks we use the command “ps -A”

![](https://lh6.googleusercontent.com/5Vn2NxmpgqXadH2HOe28d_-SfWHs4wqVuJV9UIll_AgVXw8al4iRsxyMtnj0En57iKAa6qh-pHm7XevZWULp8gDcCSwI0kBAeCY409r6WFe0eShdVUwCaFKrZlhJkBL3Wl8UuRULocWuV6n7RA)

And now to kill firefox we use “killall ProcessID” or “killall ProcessName”
```bash
$ killall firefox
```
### Task 3

To make a directory we use “mkdir dirName”
```bash
$ mkdir dir1
```
![](https://lh5.googleusercontent.com/mx1PG8sUUrmBMwYIhlROLNwwU0HzDALwEidBiXvWJH4UiHcvcM36T5h99Bhk0LUBxOVxoQuUios0tRNj_DwCfrJd385AQzErdlhIwn7i_j1xuI76Xa6v3U9nJKkoKVQEmTR8WwfOjy5S6NhnYw)

Moving file1.txt to dir1 using “mv filename.ext directory”
```bash
$ mv file1.txt dir1
```
![](https://lh5.googleusercontent.com/pQrKkWfXQNC7Um7PmJjEvxnb85N8VxsnHtsJi6PAYykE9kPHeBNW1il9goN0KQyLb--0HlWc80Syo2x0rgo3bGKiPUMkvZcK43JPLcjTCyMQ-E1Ja-d81BbcNTYK5dU-dsiSBjQM9uSrDE4TXg)
```bash
$ mkdir dir2
$ mv file2.txt dir2
```
![](https://lh4.googleusercontent.com/LQsaNR8q9MhE2XlYxfdIntBhiubL2e57z2xbLHzeFqZ5r2KoCRRPLyKzl9Kvf1QyBAlyb4L31CYdj1xZGJujMQnM13p_qRjNL1iOSWTx7UFvOt_oY8P9eIAQvURxh1anh5W16GrSmYwxP2qXkQ)

To address files inside directories we use a forward slash “/”
```bash
$ mv dir2/file2.txt dir1
```
![](https://lh4.googleusercontent.com/qoFw2OWRiyzGiG3MzY5O4hiBlJp5vDv8erhMgOfDiCZ_3go3GTelj1y0FRy_XcGHczLA4Ya5kvZ8SR6fZSn9B7e8uIhmzLA22Y2oJX0wZwXjMDkjUh8L9zjtUMiYAvBGuBoQZP6tykbUwsnIgQ)

### Task 4
To compress a directory we use “tar -zcvf archive.tar.gz folderName”
```bash
$ tar -czf zipped_directories.tar.gz dir1 dir2
```
![](https://lh6.googleusercontent.com/UTmIoblKM5IGmd_k9rr1nitARnijALqK4WXwUlCT6XuaEu4s7bi79RZN-3gqeHuIS9fl7Vbtk0zbCJ5A2llzw38-LrYjDbn6vlNvMJQhG-fRCLzUl6ZNE-iPJr1IvQ-ddz2Cpj2z6pMi1T8i2Q)

### Task 5
To extract files and folders from a compressed file we use “tar -zcvf archive.tar.gz -C /home/Labs/Documents”
If we do not provide the C flag and the path where we want to uncompress the files it explicitly uncompresses it in the current directory

Firstly making the directory Labs/Documents
```bash
$ mkdir Labs  
$ mkdir Labs/Documents
```
Now uncompressing the .tar.gz file using “tar -xvf archive.tar.gz -C Labs/Documents”
It shows the file tree that has been uncompressed
```bash
$ tar -xvf zipped_directories.tar.gz -C Labs/Documents  
dir1/  
dir1/file1.txt  
dir1/file2.txt  
dir2/
```
![](https://lh5.googleusercontent.com/6r1phl8vChhQ5tgw3Jhc1r71OtxRpe3P_winncTKPMiLyxspBD1USga5hghxg9p05xS01YU9c_d9GSi1z7Mxus3blLQK18IZxftobbsEngM_vKEbxIVrBpKLbG9yq1RhHrV9duvEslyGmIXPkQ)

### Task 6
Making a file “commands.sh”
```bash
$ touch commands.sh
```
Making the shell script executable by using “chmod +x commands.sh”
```bash
$ chmod +x commands.sh
```
Running the Script
```bash
$ ./commands.sh  
hello world  
filename commands.sh dir1 dir2 Labs zipped_directories.tar.gz  
cat: '*.txt': No such file or directory
```
Now if I make another file called LastTask.txt and add the string “aad(bbb)c c” in it the output changes to:
```bash
$ touch LastTask.txt  
$ echo "aad(bbb)c c" >> LastTask.txt  
$ ./commands.sh  
hello world  
filename LastTask
```
This Script checks all the files it can and looks for the string which contain parenthesis and removes them and the string enclosed in the parenthesis and pastes it into another file called fileName_modified.txt but if there is no file with such parenthesis then it just returns a file *_modified.txt

![](https://lh3.googleusercontent.com/nyFhY8o1OkHuxIg98YNUq1oa15acauS8h1gnjyusi7F4gKfgR_cxIvZFRIIK_B7pu9kaNzJi4qIOWLVQWbC9s0XB9zS_PIxuMKGQMwS6IaSXuZKiVPqZa3_xd9zs0FmXDbOdWSxIf-FbtLw26g)