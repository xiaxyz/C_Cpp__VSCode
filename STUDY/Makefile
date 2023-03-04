
$(shell mkdir $(OBJ_PATH) $(EXE_PATH))

SRC = $(foreach dir, $(SRC_PATH),$(wildcard $(dir)/*$(EXTENSION)))

$(EXE):$(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $(EXE_PATH)/$@

.PHONY: clean
clean:
	$(RM) $(OBJ_PATH) $(EXE_PATH)
