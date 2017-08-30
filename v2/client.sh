host=$(zenity --entry --title="The Host" --text="Enter the host to which you want to connect : ");
isRunning=true;
result="";
while $isRunning
do
	if [ -z "$result" ]; then
		result="";
	else 
		result="The list is $result \n";
	fi
	ans=$(zenity --list  --text "$result Pick an option : " --width 500 --height 300 --radiolist  --column "Choose" --column "Option" "i" Insert "s" Search "d" Delete "x" Exit);
	case $ans in
		"Insert" )
			list=$(zenity --entry --title="The List" --text="Enter the list of space seperated numbers : ");
			list="${list}" | tr -d '[:space:]';
			result=$(./mergeclient $host i $list);
			zenity --info --title="Result" --text="$(echo $result)";;
		"Search" )
			key=$(zenity --entry --title="The Key" --text="Enter the key : ");
			key="${key}" | tr -d '[:space:]';
			result1=$(./mergeclient $host s $key);
			zenity --info --title="Result" --text="$(echo $result1)";;
		"Delete" )
			key=$(zenity --entry --title="The Key" --text="Enter the key : ");
			key="${key}" | tr -d '[:space:]';
			result=$(./mergeclient $host d $key);
			zenity --info --title="Result" --text="$(echo $result)";;
		"Exit" )
			isRunning=false;
			exit 0;;
	esac
done
