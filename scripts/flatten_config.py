import json

def main():
    input_filename = "test-config.json"
    with open(input_filename, "r") as f:
        data = json.load(f)

    single_line_json = json.dumps(data, separators=(',', ':'))

    print(single_line_json)

if __name__ == "__main__":
    main()