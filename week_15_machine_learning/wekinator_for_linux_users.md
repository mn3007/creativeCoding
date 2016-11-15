For GNU/Linux users:

You might have trouble with the openJDK version of Java.

How to fix this:
* Download the Oracle version from here:
http://www.java.com/en/download/
making sure you pickup the right version (32 vs. 64 bit).

* Unzip the file contents on the desktop. They'll probably be in a folder called jre1.8.0_71

* Open a terminal and go to the desktop by typing:
cd ~/Desktop

* type: 
sudo mv jre1.8.0_71 /usr/lib/jvm
Enter you admin password to move this version of java to were all the "javas" live.

* time to make it the default java used by our system. Type:
sudo update-alternatives --install /usr/bin/java java /usr/lib/jvm/jre1.8.0_71/bin/java 2000
It will now make this java the default used by the system.

You're done :)

Close this terminal and open a new one. Go to where Wekinator is installed and type:
java -jar WekiMini.jar
It should launch the application?

Want to be able to make it run by double clicking on it? Read on....

Right click on the Wekimini.jar file and click on "Open With" or "Open With Other Application" (depending on your distribution). On the dialogue box that opens click on:
"Use a custom command" and then "Browse". In the list that opens search for "java". Click "OK" and you'll see the command that has been entered in the dialogue box. Add to it a "-jar" so that the whole command is something like:
/usr/bin/java -jar

Click OK. Enjoy!

ps. yes, I know, but GNU/Linux is good for you. It's computing's broccoli.

