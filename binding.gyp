{
	"targets": [{
		"target_name": "loole",
		"sources": [ "src/Loole.cpp", "src/main.cpp" ],
		"include_dirs" : ["<!(node -e \"require('nan')\")"]
	}]
}
