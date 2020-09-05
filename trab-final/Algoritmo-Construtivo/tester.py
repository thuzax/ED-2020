import sys
import os

if __name__=="__main__":
    input_local = "./test_instances/examples/"
    output_local = "./results/tests-ed-2020/"

    if (not os.path.exists(input_local)):
        print("INPUT FILE NOT FOUND")
        exit(0)

    test_files = os.popen("ls " + input_local).read().strip().splitlines()

    executer = "./"

    executed_file = "constr-distr.app"

    number_of_trucks = "5"

    executed_commands = []
    final_results = []
    errors = []

    trials = [i for i in range(5)]

    for test_file in test_files:
        for trial in trials:
            output_name = test_file.split(".")[0] + "-" + str(trial) + ".json"

            command = ""
            command += executer + executed_file + " "
            command += input_local + test_file + " "
            command += output_local + output_name + " "
            print(command)

            executed_commands.append(command)
            returned = os.popen(command).readlines()
            print(returned)
            final_results.append(returned)


    # print(final_results)
    text_errors = ""
    for error in errors:
        text_errors += error + "\n"

    with open("./tests_with_errors.txt", "w") as err_out:
        err_out.write(text_errors)