# Contributing Guidelines

### Follow the guidelines on how to create issues, Fork a repo, makes changes, and ask the maintainers to review and merge it.

## Creating issue

Issues can be used to keep track of all the new problems that are to be added and are also helpful in comparing with the existing codebase.

#### DO NOT MAKE PR WITHOUT CREATING AN ISSUE

1. Click on the issues tab.<br>
   <img src="./assets/issue1.PNG">

2. Click on new issue if any of the already present issues do not interest you.<br>
   <img src="./assets/issue2.PNG">

3. Click on Get started.<br>
   <img src="./assets/issue3.PNG">

4. Enter name of the issue and submit.<br>
   <img src="./assets/issue4.PNG">

#### Wait for the issue to be assigned to you

## Making a PULL REQUEST

Pull requests are to be made after an issue has been assigned to you.<br>
These Guidelines will teach how to contribute to any other people's repository in general and not limited to this repository.

1. <b>Fork</b> the repository.<br> Forking the repository makes a local copy of the parent repository in your Github account.<br>

<img src = "./assets/fork.PNG" >

2. Now move to your forked repository in your account.<br>Click on the <b>Code</b> button in green and copy the link to the repository.<br>
   <img src="./assets/code.PNG">

3. Now move to your code editor and open terminal.<br>
   Move to your desired path in the terminal and enter this command.<br>
   <img src="./assets/clone.PNG" width="400">

Don't forget, you have to copy from your own forked repository so that it contains your username in the code link.

4. Now cd to the folder of the repository.<br>
   <img src = "./assets/cd.PNG" width="400">

5. Now you have to create a new branch<br>
   Switch to Development Branch. Never develop on Master Branch. Push in the command: <br><code>git checkout < YOURUSERNAME ></code>
   <br>
   <img src="./assets/branch.PNG" width="400">
   <img src="./assets/branch2.PNG" width="400">

6. Start Coding. Make commits with proper commit messages. <br>
   After you have made changes/ added new files
   write these commands -<br>
   <code> git add .</code><br>
   <code> git commit -m "commit message"</code><br>

#### You have committed your changes in the local machine, but there might be possibility that someone before you have made changes and even made PR before you.<br><br> So it is advised to Pull code from the master branch to your local branch or more specifically keep your Fork in sync with repository<br>

for that write this command after commiting-<br>
<code> git pull</code><br>
After that you can go on and push your changes<br>
<code> git push</code><br>

7.
