## Getting automatic updates to the class material

1. Go to the department's gitlab page [http://gitlab.doc.gold.ac.uk](http://gitlab.doc.gold.ac.uk) and login using the CAMPUS method. Enter your campus login & password.

2. If you already have a public key on your machine jump to step 3. Otherwise, open a terminal and type:
```ssh-keygen -t rsa -b 4096 -C "your_email@example.com"```
  * system will say: __Enter file in which to save the key (/Users/you/.ssh/id_rsa):__ and you should press Enter.
  * system will say: __Enter passphrase (empty for no passphrase):__. Press Enter again.
  * system will say: __Enter same passphrase again:__. Press Enter once more.

3. Type in the terminal:
```more ~/.ssh/id_rsa.pub```
  * highlight with the mouse what it prints out and copy it.

4. Go to: [http://gitlab.doc.gold.ac.uk/profile/keys](http://gitlab.doc.gold.ac.uk/profile/keys) and press __SSH keys__ (on left-hand side), then __Add SSH key__ on the right-hand side, give a title to your key and paste what you copied in the "Key" section.

5. Go to [http://sparkleshare.org/](http://sparkleshare.org/) and download the appropriate executable for your operating system. If you are using Ubuntu (well done!) open the terminal and simply type:
```sudo apt-get install sparkleshare```

6. After installing sparkleshare it should have an icon on the tray. Click on it, go over "SparkleShare" then over "Client ID" and click on "Copy to Clipboard". Repeat step 4 only this time give it a new title and paste what you have now copied.

7. Click again on the SparkleShare icon, go to "SparkleShare" and click on "Add Hosted Project". In the dialog box that opens, select "On my own server" and:
  * in the "Address" field enter: __ssh://git@gitlab.doc.gold.ac.uk__
  * in the "Remote Path" enter: __comp_arts_2015/workshops_in_creative_coding.git__
  * click the "Add" button (and cross your fingers). If it works it should start downloading stuff.

8. Repeat again step 7 doing exactly the same things only this time in the "Remote Path" field enter: __comp_arts_2015/sandbox.git__

9. If everything worked you should have 2 folders in the "SparkleShare" folder in your home folder.
