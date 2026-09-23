# Проверка, что все учебные программы компилируются.
#   make check          — собрать все задачи (без запуска)
#   make run FILE=path  — собрать и запустить одну программу

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall
BUILD    := build

# Qt-проекты собираются через qmake, поэтому исключены
SOURCES := $(shell find tasks playground -name "*.cpp" \
             -not -path "*/pr21-qt-journal/*" -not -path "*/toynote/*" | sort)

.PHONY: check run clean

check:
	@mkdir -p $(BUILD)
	@fail=0; for f in $(SOURCES); do \
		if $(CXX) $(CXXFLAGS) -w "$$f" -o $(BUILD)/check.out 2>/dev/null; then \
			echo "  ok    $$f"; \
		else \
			echo "  FAIL  $$f"; fail=1; \
		fi; \
	done; rm -f $(BUILD)/check.out; exit $$fail

run:
	@test -n "$(FILE)" || (echo "Usage: make run FILE=tasks/z-tasks/block-01/z01.cpp" && exit 1)
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) "$(FILE)" -o $(BUILD)/program && ./$(BUILD)/program

clean:
	rm -rf $(BUILD)
