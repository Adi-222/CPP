from fpdf import FPDF

class PDF(FPDF):
    def header(self):
        self.set_font('DejaVu', 'B', 14)
        self.cell(0, 10, 'Module IV: Software Reliability, Testing and Maintenance - Mind Map Style', 0, 1, 'C')
        self.ln(5)

    def chapter_title(self, num, title):
        self.set_font('DejaVu', 'B', 12)
        self.set_text_color(0, 0, 128)
        self.cell(0, 10, f"{num}. {title}", 0, 1)
        self.set_text_color(0, 0, 0)

    def chapter_body(self, body):
        self.set_font('DejaVu', '', 11)
        self.multi_cell(0, 8, body)
        self.ln()

def main():
    pdf = PDF()
    pdf.add_page()

    # Change these paths if you saved fonts elsewhere
    pdf.add_font('DejaVu', '', '/Users/user/Fonts/DejaVuSans.ttf', uni=True)
    pdf.add_font('DejaVu', 'B', '/Users/user/Fonts/DejaVuSans-Bold.ttf', uni=True)

    data = [
        ("Define software failure and fault. How do they differ?",
         "• Fault: Defect or bug in code\n"
         "• Failure: When fault causes incorrect output during execution\n"
         "• Difference: Fault is the cause; failure is the effect"),
        
        ("Basic reliability model and assumptions",
         "• Measures probability software works without failure over time\n"
         "• Assumes:\n"
         "  - Constant failure rate\n"
         "  - Failures are independent\n"
         "  - Fixes reduce failure rate"),
        
        ("Logarithmic Poisson Reliability Model",
         "• Failure rate decreases exponentially over time\n"
         "• Formula: λ(t) = λ0 * e^(-θt)\n"
         "• λ(t): failure intensity, t: time, θ: decay rate constant"),
        
        ("Key components of software process",
         "• Specification (requirements)\n"
         "• Design (architecture)\n"
         "• Implementation (coding)\n"
         "• Validation (testing)\n"
         "• Evolution (maintenance)\n"
         "• People, tools, and methods involved"),
        
        ("Functional testing & Boundary Value Analysis (BVA)",
         "• Functional Testing: Verify system does what it should\n"
         "• BVA: Test at boundary limits of input values\n"
         "• Example: Input range 1-100, test 0,1,100,101"),
        
        ("Equivalence Class Testing",
         "• Group inputs into classes (valid & invalid)\n"
         "• Test one value from each class\n"
         "• Example: Age 18-60 → test 25 (valid), 17 & 61 (invalid)"),
        
        ("Decision Table Testing",
         "• Tabular representation of inputs and rules\n"
         "• Rows: conditions and actions\n"
         "• Example: ATM system\n"
         "  - Conditions: Card valid? PIN correct?\n"
         "  - Actions: Allow withdrawal / Reject"),
        
        ("Cause-Effect Graphing Technique",
         "• Graph of input causes & output effects\n"
         "• Converts graph into decision table\n"
         "• Helps find missing or extra logic"),
        
        ("Structural Testing & Path Testing",
         "• Structural testing: Based on code structure\n"
         "• Path testing: Test all possible execution paths\n"
         "• Example: if-else — test both branches"),
        
        ("Data Flow Testing & Mutation Testing",
         "• Data flow: Test variable definitions and uses\n"
         "• Mutation: Introduce small code changes ('mutants') to test if faults are detected"),
        
        ("Cyclomatic Complexity",
         "• Measures number of independent paths in code\n"
         "• Formula: M = E - N + 2P (Edges - Nodes + 2 × connected components)\n"
         "• Higher value → more complex code"),
        
        ("Unit, Integration, and System Testing",
         "• Unit Testing: Test single modules\n"
         "• Integration Testing: Test combined modules\n"
         "• System Testing: Test whole system behavior"),
        
        ("Types of software maintenance",
         "• Corrective: Fix bugs\n"
         "• Adaptive: Adjust to environment changes\n"
         "• Perfective: Improve performance or features\n"
         "• Preventive: Prevent future problems"),
        
        ("Software maintenance process & models",
         "• Steps: Analyze → Modify → Test → Deliver\n"
         "• Models: Quick-fix, Iterative, Reuse-based"),
        
        ("Software reengineering concepts",
         "• Reengineering: Improve software by redesigning\n"
         "• Reverse Engineering: Extract design from existing code\n"
         "• Forward Engineering: Build new software from design\n"
         "• Example: Upgrade old payroll system to web-based system")
    ]

    for i, (title, body) in enumerate(data, 43):
        pdf.chapter_title(i, title)
        pdf.chapter_body(body)

    pdf.output("Module_IV_Summary.pdf")
    print("PDF generated: Module_IV_Summary.pdf")

if __name__ == "__main__":
    main()
