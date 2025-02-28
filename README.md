# wxMarkDown editor
A simple MarkDown Editor written in C++ using

-  [wxWidgets](https://github.com/wxWidgets/wxWidgets) 
- [maddy](https://github.com/progsource/maddy) markdown parser

## Features
- Live preview
- simple syntax highliting
- customizable themes
- fast and lightweight, minimal dependencies
- Unix and Windows compatible

__For the list of the supported markdown definitions, please visit [maddy project page](https://github.com/progsource/maddy/blob/master/docs/definitions.md)__

## Build from source
### Requirements
- a compiled version of `wxWidgets with` compatibility 3.2.1+
- cmake
- modern compiler


1. Clone the repository


```
git clone https://github.com/fszontagh/wxmarkdowneditor.git
```

2. Create a build dir:

```
mkdir wxmarkdowneditor/build; cd wxmarkdowneditor/build
```


3. Configure


```
cmake ..
```

4. Build


```
cmake --build ..
```

## Sample screenshots