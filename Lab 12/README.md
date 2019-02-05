# Lab 12: File Systems

## Tasks
- You need to create two simple text files named file1.txt and file3.txt whose contents are unique sentences. 
- Next, obtain the inode number of this file with the command “ls -li file1.txt”. 
- The UNIX ln command creates a link between a source and target file. This command works as follows: ln [-s] \<source file\> \<target file\>
- Enter the following command to create a **hard link** between file1.txt and file2.txt: “ln file1.txt file2.txt” What are the inode values of file1.txt and file2.txt? Are they the same or different? 
*Do the two files have the same—or different—contents?*
- Next, edit file2.txt and change its contents. After you have done so, examine the contents of file1.txt.
*Are the contents of file1.txt and file2.txt the same or different?*
- Next, enter the following command which removes file1.txt: “rm file1.txt”.
*Does file2.txt still exist as well?*
- Now examine the man pages for both the rm and unlink commands. Afterwards, remove file2.txt by entering the command “strace rm file2.txt” The strace command traces the execution of system calls as the command rm file2.txt is run.
*What system call is used for removing file2.txt?*
- Create a soft link to file3.txt by entering the following command: “ln -s file3.txt file4.txt”
- After you have done so, obtain the inode numbers of file3.txt and file4.txt using the command: “ls -li file*.txt” 
*Are the inodes the same, or is each unique?*
- Next, edit the contents of file4.txt.
*Have the contents of file3.txt been altered as well?*
- Last, delete file3.txt.
*Explain what happens when you attempt to edit file4.txt*
### Making Files

![](https://lh3.googleusercontent.com/m5lmHN9I-BIpRbVANf3lsD3UnE6FWglZXBgoPEvlfEPfEc_i-p4XcoU0H7_OBTuSh6kDgdRpr2izTB5c7mQxw5-jmiQk1BcMapPzw3mSprE-uwcZ8miAXYzyCZxT_XrzI1JmnDkj)

In this task, I made two files with different data (‘subl’ is the command to open the file in the ‘Sublime Text’ Editor). ‘touch’ is used to create A new file.

### Checking Inode Number

![](https://lh6.googleusercontent.com/TYF_ihprqBzHZqlPR8Q-lpn15s9V-0DBh0vIRy2ew9_6Xg1edbtbIS5bWMmDWK09SK7GFJsXR3JPBN-5264-705l3sGBiO8Q3h96Jzacrex8Ghe9Luhthlw-EIQw_1zQEvsVHXuB)

This screenshot shows the inode number of the file1.txt (and file3.txt) and the creator of the file and date and time and some flags which probably tell that the file is readable and writable.

### Creating a Hard Link

![](https://lh5.googleusercontent.com/XUIwV8uo_abrTQxf3_g1r75VZp7gi_MhQvjMErcGU-UApbb2j4uXK52LUa45Bd9irxFDuIImYE60FTP7vH6vUUNxUkL5Jy-Zp6RUqPUUm0HDJuh0PfqblgbPZQ5o8X2-zhCdWTyR)

```
What are the inode values of file1.txt and file2.txt? Are they the same or different? Do the two files have the same—or different—contents?

This command is used to create the hard link. ‘ln file1.txt file2.txt’ and a new file is created with the exact same content and the inode number as the file1.
```

![](https://lh4.googleusercontent.com/UgtOtlRm0EwICMthMrMeZHfLOPPhterOfnQV1Voe_reY_E4OozuDZ-dRsvLkt1t8txlWpMlGCfyFWQQlL1vYmklgVJolU7ru7QPWbKgqjboNNq30B49GhpHC8nxecLmLz1r6yoFy)

### Editing the Linking File

![](https://lh5.googleusercontent.com/oFP7Bk_rErbn4jgoReGcq1OrzhhKrY-SaOnZuc_-upnQwHDfCKOcypA4zRowoAk5SRONOD3cVGZYVPl9G_n1TGvUuMFsAMMgCWH3D-R_hj4d91itVHCLwdevt3uFdD7Q6ZxOAiWB)

If i edit the file2.txt, we see that the file1.txt contents are also edited.

### Removing file2.txt

![](https://lh4.googleusercontent.com/0GL0BI7T8lRCyVfuybnK45qZ57L7-mJXxnBbaTd0HCZQ-JhJnC3Bss8AYk29vVqR4v-BFA1rMNFX1Z--virih7FQSiufFCE0E95ywqF3pDD7936InZkknVqSV0F8IpiK0QgZ15zW)

```
After Deleting the file1.txt. Does file2.txt still exist as well?

I Deleted the file1.txt using the ‘rm file1.txt’ command and then it is observed that the contents of the file2.txt remain.
The inode number of the file2.txt is the same as before.
```
### Strace rm file2.txt

shahzaib:Lab 12$ strace rm file2.txt  
execve("/bin/rm", ["rm", "file2.txt"], 0x7ffc4044dbd8 /* 68 vars */) = 0  
....
....

![](https://lh6.googleusercontent.com/4rdTKBnv5yw_xC9UrvwpBoyzq8itDDXhpmwCXB3Wq9T6AxRXFDK_AWMB_Datsf7PJE-Sohv14BI2FfCTi6QyF3a3u2JeNd0SUmnefDCBFmmQDTIKKME4PAgX_cY9ixxkXdUoktTk)

```
What system call is used for removing file2.txt?

The ‘rm’ command is responsible for deleting the file.
```
### Creating a Soft Link

![](https://lh3.googleusercontent.com/WaM-suAJgPnxZtqbVoEIJ3OxwkbbWj9_9sQUTAbRZ6DFNyVqrNZiOJXEGS39I5YQgMsWjdjZpwUDnXWVMTi3FJertEDYlOBTmcdVLJi8OyZ-AKj9NOOXppLPcT67_6erLoGaJGK2)

The command ‘ln -s file3.txt file4.txt’ is used to create a symbolic link between the two files.

Ubuntu’s file Explorer views the icon of the symbolic file differently (there is a little arrow with this file).

### Inode Numbers (Symbolic Linked Files)

Now i used the ‘ls -li file*.txt’ to obtain the inode information of all the files with names starting with ‘file’ and ending with ‘.txt’.

![](https://lh3.googleusercontent.com/lWVHNwRe1UwcMyAsuuQjEGQ0_gQkxW7fvSeu8F400OhVOFpJ9wNy1RWRvCB0dCu34mnBXknTocogVSxbHF3N6TtJdBK_9t2QHmsclOR4tAuRvXxjYze7Gj9Ct1494ZC6LlcLS0mq)

### Editing the Contents of file4.txt

The Contents of both the files are changed when we edit the file4.txt

![](https://lh6.googleusercontent.com/-M2Rg0VnVf1nDxB3xuzgU3zZrFUrafYdpOrSFF0aNeBW6SBUY0anYeRjekRf5nWXwcOwzRnYKboNY1cM8DtTOZHnT-Oai6fLXAxv2jd5Q4fWZSvTLHEiVhV6Lr5N6RcI2mzdC4H7)

```
Are the inodes the same, or is each unique? Next, edit the contents of file4.txt. Have the contents of file3.txt been altered as well?

The inodes are different for these files.
Yes the Contents of the file3.txt have also been altered when i altered the file4.txt
```
### Deleting file3.txt

![](https://lh4.googleusercontent.com/iZzR6JbY6ng-sjHF-0mgqkTtOhnchhs5OJpL04fDCCseIawz-GMLNHzvHXWpiNpSedmMzjg3HM-tL3G-qBy7gDDmt17icVdcnOUljeRQTBDbEnkqRAj5uIO5CGIqmXojXc51M5Yi)

```
Last, delete file3.txt. After you have done so, explain what happens when you attempt to edit file4.txt.

After i have deleted the file3.txt and then tried to edit the file4.txt and then saving the file4.txt the OS immediately brings back the deleted file and it is updated.
Softlink does not allow the file to be deleted as the link is needed for the soft linked file to exist.
```
![](https://lh3.googleusercontent.com/Y4gADuClfK-xzlia6fs8JRPRnidJwGEOAvzr8YxeEeEVSZ88fQTO79I4gvLhCravLC-mJxwW1B2q9dMqRjhi1lCbLQPl1HvHDYKP77C9VrBGeGa9rblU7xFGwBt8P_SHYzvUD6NE)

The inode Number prevents this.

![](https://lh4.googleusercontent.com/sQwQnVXN7nfFc4RNu3s6caj9BquJQN-aLz5AV_QbCR3AUjJLHI24FfkYWhV5KIC04BUj1u2AgeucCJtUrInPP18yISVc0s1Im8GXEKoo1jwaqvBzU6CgOzxfIweFqAqU5Ji8jEn7)