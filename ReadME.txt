Project Summary:
My project is a simple database for all zip codes in the entire United States. It uses the
"cities.cvs" file which contains all the US zip codes, the cities the zip codes refer
to, the state which the city is in, and the latitude longitude coordiantes of that zipcode.
It works by organizing the data into a series of vectors through the use of getline. 
The first vector is all of the states,each state has a vector of all its cities, each city
has a vector of all its zip codes, and each zip code has its latitude longitude coordinates. 
Each line in the cities.cvs folderlooks similar to this:
	35004,AL,Acmar,33.584123,-86.51557
The code first implements the data by state. It searches throught the state vector to find the
state in the line of data. In this instance the code would look for Alabama or AL. Once it finds
the state it then goes through that states city vector looking for the city in the line of data.
In this case that would be Acmar. Once it finds that city it then goes through that city's zip
code vector where it stores the zip code, latitude, and longitude data. If the state cannot be 
found then it adds the state in the line of data to the state vector. If the city cannot be
found then it adds the city in the line of data to the state's city vector.
Once the vectors are constructed, the user can search for zip codes and cities as well as delete
them if they so wish. There are also options to modify and add zip codes.

How to Run:
To run my program copy the file called Final to your Dropbox folder then open up the Virtual
Machine we have been using all year for class. Once inside the Virtual Machine go to the file
manager and open up the Final folder in the terminal. This can be done by right clicking on 
the Final folder and selecting "open in Terminal". The terminal should open up. Type this into
the command line:
	./USzipCodes
This will run my program.

Dependencies:
None, the zip code program uses basic libraries.

System Requirements:
Please run on Linux, this is why in the "How to Run" section I tell you to go into the 
Virtual Machine. If your computer's OS is Linux then you won't have to run on the Virtual
Machine.

Group Members:
Alexander Hamlet

Contributors:
None

Open issues/bugs:
I couldn't get the "delete zip code" funtion to work. This is an option the user has, but I was
having trouble deleting a single value from a vector. The user can successfully operate this
function, but if the code runs into the point in memory at any time a seg fault will appear.

