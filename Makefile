CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Iinclude -Itests  -Iapp -MMD -MP

SRC_DIR   := src
TEST_DIR  := tests
APP_DIR   := app
BUILD_DIR := build

SRCS := $(filter-out $(SRC_DIR)/main.cpp,$(wildcard $(SRC_DIR)/*.cpp))
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
APP_SRCS := $(wildcard $(APP_DIR)/*.cpp)
APP_OBJS := $(patsubst $(APP_DIR)/%.cpp,$(BUILD_DIR)/app/%.o,$(APP_SRCS))
APP_BIN  := $(BUILD_DIR)/loja
.PHONY: all clean

all: $(OBJS)

$(BUILD_DIR)/app/%.o: $(APP_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(APP_BIN): $(OBJS) $(APP_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(APP_BIN)
	./$(APP_BIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d $(BUILD_DIR)/tests $(TEST_BIN) \
		   $(BUILD_DIR)/app $(APP_BIN) $(APP_BIN).exe \
	       $(BUILD_DIR)/*.gcda $(BUILD_DIR)/*.gcno $(BUILD_DIR)/cobertura


TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))
TEST_BIN  := $(BUILD_DIR)/testes

.PHONY: test

$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_BIN): $(OBJS) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)


.PHONY: coverage

coverage: clean
	$(MAKE) $(TEST_BIN) CXXFLAGS="$(CXXFLAGS) --coverage -O0"
	-./$(TEST_BIN)
	rm -f $(OBJS) $(TEST_OBJS) $(TEST_BIN)
	@mkdir -p $(BUILD_DIR)/cobertura
	gcovr -r . --filter $(SRC_DIR)/ --print-summary \
	      --html-details $(BUILD_DIR)/cobertura/index.html  
		  
-include $(wildcard $(BUILD_DIR)/*.d $(BUILD_DIR)/tests/*.d $(BUILD_DIR)/app/*.d)
