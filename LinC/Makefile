#	Configuaration
CC := gcc
Extension := .c

#	C Source Code
Source := C_Source
Include := C_Include

#	Build Folder
Build := ../../bin/

#	Build Target
Target := so
Flags := -O2 -g -Wall -Wextra

#	Library
LibraryFolder := ./
LibraryName := c_bridge
Library := $(LibraryName).$(Target)
LibraryPath := $(LibraryFolder)$(Library)

#	Loading in file locations
Sources := 									\
	$(wildcard $(Source)**/**$(Extension))	\
	$(wildcard $(Source)*$(Extension))
Objects := 													   	\
	$(patsubst $(Source)%$(Extension), $(Build)%.o, $(Sources))

#	Handling automatic dependency tracking
Dependencies := $(patsubst %.o, %.d, $(Objects))
-include $(Dependencies)
DependenciesFlags = -MMD -MF $(@:.o=.d)

#	Build Shared Library
build: $(Objects)
	@echo [INFO] Creating Shared Library [$(Target)] ...
	@$(CC) -fPIC -shared -o $(LibraryPath) $^
	@echo [INFO] [$(Library)] Created!

$(Build)%.o: $(Source)%$(Extension)
	@echo [CC] $<
	@mkdir -p $(@D)
	@$(CC) -fPIC $< -c -o $@ 	\
		$(Flags) 				\
		$(DependenciesFlags) 	\
		-I$(Include)

#	Reset Build Environment
.PHONEY: clean
clean:
	@rm -rf $(Build)
	@rm -rf $(DEPS)
	@rm $(LibraryPath)
