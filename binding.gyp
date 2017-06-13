{
	"targets": [{
		"target_name": "loole",
		"sources": [ "src/*.cpp" ],
		"include_dirs" : ["<!(node -e \"require('nan')\")"]
	}]
}
